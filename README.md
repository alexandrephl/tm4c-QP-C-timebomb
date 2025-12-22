# TM4C123 “TimeBomb” — QP/C Active Object Demo (with QSPY tracing)

![EK-TM4C123GXL LaunchPad](img/pic_board.jpg)

An event-driven demo on the EK-TM4C123GXL (TM4C123GH6PM) using QP/C.
It showcases a hierarchical state machine, time events, and live runtime tracing via QSPY over UART0.

---

##  Repository Layout

|  
├── Application/                 	# Your application logic (main, bsp)  
|  
├── QPC/               		    	# QP/C framework sources (QF, QActive, ports, etc.)  
|  
├── ek-tm4c123gxl/               	# Board/Microcontroller-specific files, startup code etc.  
|  
├── CMSIS/               		    # CMSIS core headers  
|  
├── targetConfig/                	# CCS Target Configurations  
|  
├── QS/                				# QSPY tool setup scripts  

---

## Build & Run Instructions

### Prerequisites

- **Code Composer Studio (CCS)** v12 or later  
- **EK-TM4C123GXL** LaunchPad  
- **TivaWare SDK** (for low-level drivers, not bundled in repo)
- **QTools package** from Quantum Leaps (for QSPY, not bundled in repo)

### To Build:

1. **Import project**:
  - `File → Import → Code Composer Studio → CCS Projects` → select this repo’s root folder.
2. **Set build variable for TivaWare (once)**:
	-In CCS: *Project → Properties → C/C++ Build → Build Variables*:
		Add: 
		•	Name: TIVAWARE_ROOT
		•	Value: your TivaWare path (e.g. C:/ti/TivaWare_C_Series-2.2.0.295)
5. **Build and flash**:
	- Connect the LaunchPad via USB  
	- Click the debug icon or *Run → Debug* to flash and start execution.

## How It Works

This project implements a small reactive system following the Active Object design pattern provided by QP/C.
The logic is entirely event-driven: no polling loops, only asynchronous event dispatching.

### Main Concept

The **TimeBomb Active Object** models a simple countdown device with arm/disarm control:
- When the user **presses SW1**, the TimeBomb starts the countdown (if armed).  
- **SW2** toggles between *disarmed* and *armed* states.  
  - When *disarmed*, the bomb is safe and SW1 has no effect.  
  - When *armed*, SW1 re-starts the countdown.  
- After the countdown finishes, it enters the **“boom”** state — all LEDs on.  
- The system can then be reset manually or by restarting.  

## QSPY Tracing

QS (Quantum Spy) tracing is fully integrated via UART0 @ 115200 baud.
You can view all runtime events, button changes, and LED transitions in real time.

IMPORTANT : To enable tracing, make sure the Spy build configuration is active in Code Composer Studio:
Project → Build Configurations → Set Active → spy

### Run QSPY

•	Mac/Linux:  
    cd /path/to/qtools/bin./qspy -c /dev/cu.usbmodemXXXX -b 115200
    # or ./qspy -c /dev/ttyACM0 -b 115200 on Linux  
•	Windows:  
    qspy.exe -c COM5 -b 115200

## License & Credits

	- Main application code: MIT (see `LICENSE.txt`)
	- Third-party components and their licenses: see `THIRD_PARTY_NOTICES.md`

## Author
**Alexandre Panhaleux**  
Embedded Software Engineer  
[GitHub: @alexandrephl](https://github.com/alexandrephl)
