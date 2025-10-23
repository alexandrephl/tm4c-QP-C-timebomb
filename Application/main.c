/******************************************************************************
* @file    main.c
* @brief   EK-TM4C123GXL "TimeBomb" demo using QP/C (QF + QTimeEvt)
* @board   EK-TM4C123GXL (TM4C123GH6PM)
* @author  Alexandre Panhaleux
******************************************************************************/

#include "qpc.h"   // QP/C framework (QF, QHSM, QActive, QTimeEvt)
#include "bsp.h"   // Board support (LEDs, buttons, tick rate, etc.)


Q_DEFINE_THIS_MODULE("main") /* module tag for assertions */

/* The TimeBomb AO =========================================================*/
typedef struct {
    QActive super; /* base class */

    QTimeEvt te; /* Time event (TIMEOUT_SIG) */
    uint32_t blink_ctr; /* remaining blinks before "boom" */
} TimeBomb;

/* constructor declaration */
static void TimeBomb_ctor(TimeBomb * const me);

/* State handlers */
static QState TimeBomb_initial(TimeBomb * const me, void const * const par);
static QState TimeBomb_defused(TimeBomb * const me, QEvt const * const e);
static QState TimeBomb_armed(TimeBomb * const me, QEvt const * const e);
static QState TimeBomb_wait4button(TimeBomb * const me, QEvt const * const e);
static QState TimeBomb_blink(TimeBomb * const me, QEvt const * const e);
static QState TimeBomb_pause(TimeBomb * const me, QEvt const * const e);
static QState TimeBomb_boom(TimeBomb * const me, QEvt const * const e);

/* Version guard =========================================================*/
#if (QP_VERSION < 730U) || (QP_VERSION != ((QP_RELEASE^4294967295U)%0x2710U))
#error "qpc version 7.3.0 or higher required"
#endif

/* State machine =========================================================*/
/* Initial transition for the TimeBomb AO */
static QState TimeBomb_initial(TimeBomb * const me, void const * const par) {

    /* QS dictionaries for tracing*/
    QS_OBJ_DICTIONARY(&me->te);
    QS_FUN_DICTIONARY(&TimeBomb_defused);
    QS_FUN_DICTIONARY(&TimeBomb_armed);
    QS_FUN_DICTIONARY(&TimeBomb_wait4button);
    QS_FUN_DICTIONARY(&TimeBomb_blink);
    QS_FUN_DICTIONARY(&TimeBomb_pause);
    QS_FUN_DICTIONARY(&TimeBomb_boom);

    return Q_TRAN(&TimeBomb_wait4button);
}

/*
 * Superstate “armed”
 * Superstate for normal arming/blinking sequence.
 */
static QState TimeBomb_armed(TimeBomb * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        case Q_EXIT_SIG: {
            BSP_ledRedOff();
            BSP_ledGreenOff();
            BSP_ledBlueOff();
            status_ = Q_HANDLED();
            break;
        }
        case Q_INIT_SIG: {
            status_ = Q_TRAN(&TimeBomb_wait4button);
            break;
        }
        case BUTTON2_PRESSED_SIG: {
            status_ = Q_TRAN(&TimeBomb_defused);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

/*
 * Idle (waiting) state
 * Entry: green ON. On BUTTON_PRESSED → blink (set blink_ctr=5).
 */
static QState TimeBomb_wait4button(TimeBomb * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            BSP_ledGreenOn();
            status_ = Q_HANDLED();
            break;
        }
        case Q_EXIT_SIG: {
            BSP_ledGreenOff();
            status_ = Q_HANDLED();
            break;
        }
        case BUTTON_PRESSED_SIG: {
            me->blink_ctr = 5U;
            status_ = Q_TRAN(&TimeBomb_blink);
            break;
        }
        default: {
            status_ = Q_SUPER(&TimeBomb_armed);
            break;
        }
    }
    return status_;
}

/**
 * Active blinking state
 *
 * Entry: red ON; arm one-shot 0.5 s timer → TIMEOUT → pause.
 */
static QState TimeBomb_blink(TimeBomb * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            BSP_ledRedOn();
            QTimeEvt_armX(&me->te, BSP_TICKS_PER_SEC/2, 0U);
            status_ = Q_HANDLED();
            break;
        }
        case Q_EXIT_SIG: {
            BSP_ledRedOff();
            status_ = Q_HANDLED();
            break;
        }
        case TIMEOUT_SIG: {
            status_ = Q_TRAN(&TimeBomb_pause);
            break;
        }
        default: {
            status_ = Q_SUPER(&TimeBomb_armed);
            break;
        }
    }
    return status_;
}

/**
 * Pause state
 *
 * Entry: arm one-shot 0.5 s; TIMEOUT → decrement, loop blink/pause until 0;
 * when count hits 0 → boom.
 */
static QState TimeBomb_pause(TimeBomb * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            QTimeEvt_armX(&me->te, BSP_TICKS_PER_SEC/2, 0U);
            status_ = Q_HANDLED();
            break;
        }
        case TIMEOUT_SIG: {
            --me->blink_ctr;
            if (me->blink_ctr > 0U) {
                status_ = Q_TRAN(&TimeBomb_blink);
            }
            else {
                status_ = Q_TRAN(&TimeBomb_boom);
            }
            break;
        }
        default: {
            status_ = Q_SUPER(&TimeBomb_armed);
            break;
        }
    }
    return status_;
}

/**
 * Final “explosion” state
 *
 * Entry: all LEDs ON; no transitions (other than via superstate).
 */
static QState TimeBomb_boom(TimeBomb * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            BSP_ledRedOn();
            BSP_ledGreenOn();
            BSP_ledBlueOn();
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&TimeBomb_armed);
            break;
        }
    }
    return status_;
}

/**
 * Defused state (sibling of armed)
 *
 * Entry: blue ON; BUTTON2_PRESSED → back to armed (all LEDs off via armed EXIT).
 */
static QState TimeBomb_defused(TimeBomb * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            BSP_ledBlueOn();
            status_ = Q_HANDLED();
            break;
        }
        case Q_EXIT_SIG: {
            BSP_ledBlueOff();
            status_ = Q_HANDLED();
            break;
        }
        case BUTTON2_PRESSED_SIG: {
            status_ = Q_TRAN(&TimeBomb_armed);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

/* Constructor =========================================================*/
static void TimeBomb_ctor(TimeBomb * const me) {
    QActive_ctor(&me->super, (QStateHandler)&TimeBomb_initial);
    QTimeEvt_ctorX(&me->te, &me->super, TIMEOUT_SIG, 0U);
}

/* AO instance and queue =========================================================*/

static QEvt const *timeBomb_queue[32];  /* Storage for TimeBomb's event queue  */
static TimeBomb timeBomb;               /* AO instance */
QActive *AO_timeBomb = &timeBomb.super;



/* the main function =========================================================*/
int main() {

    BSP_init(); /* initialize the BSP */
    QF_init();   /* initialize the QP framework */


    /* create AO and start it */
    TimeBomb_ctor(&timeBomb);
    QACTIVE_START(AO_timeBomb,
                  2U,                               /* priority (1-based) */
                  timeBomb_queue,
                  Q_DIM(timeBomb_queue),
                  (void *)0, 0U,
                  (void *)0);


    QF_run(); /* Enter the QP framework's scheduler/event loop (never returns) */
    return 0; /* NOTE: the scheduler does NOT return */
}

