/******************************************************************************
* @file    bsp.h
* @brief   Board Support Package interface for EK-TM4C123GXL (QP/C TimeBomb)
* @board   EK-TM4C123GXL (TM4C123GH6PM)
* @author  Alexandre Panhaleux
******************************************************************************/
#ifndef BSP_H
#define BSP_H

/* System tick rate and configuration parameters of QP, =========================================================*/
#define BSP_TICKS_PER_SEC 100U
#define QF_MAX_SIG 16U
#define QF_MAX_TICK_RATE 1U

/* Public API =========================================================*/
void BSP_init(void);
void BSP_start(void);

void BSP_ledRedOn(void);
void BSP_ledRedOff(void);
void BSP_ledBlueOn(void);
void BSP_ledBlueOff(void);
void BSP_ledGreenOn(void);
void BSP_ledGreenOff(void);

/* global RTOS objects... */
enum EventSignals {
    BUTTON_PRESSED_SIG = Q_USER_SIG,
    BUTTON_RELEASED_SIG,
    BUTTON2_PRESSED_SIG,
    BUTTON2_RELEASED_SIG,
    TIMEOUT_SIG,
    MAX_SIG
};

/* Extern Active object */
extern QActive *AO_timeBomb;

#endif /* BSP_H */
