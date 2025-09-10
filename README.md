# 🚗Simulation-of--ECU-Application-Layer-

⚙️ Requirements

Install MinGW-w64 C/C++/Fortran Compiler

Download from: MATLAB Support for MinGW-w64

Install and configure it with MATLAB.

Install FMU Builder for Simulink

Download from: FMU Builder for Simulink

matlab over 2022

This is required to export models to FMU (Functional Mock-up Unit) format.

🛠️ Compilation with S-Function Builder

Put your C++ source code in the S-Function Builder (e.g. SERVICEECU.cpp and SERVICEECU_wrapper.cpp).

Open MATLAB Command Window and run:

mex -R2018a CXXFLAGS="$CXXFLAGS -std=c++17" SERVICEECU.cpp SERVICEECU_wrapper.cpp


✅ This ensures your code is compiled with C++17 standard.

🔄 Export to FMU in Simulink

In Simulink, go to:

Modeling → Model Settings

Under Simulation Target → set Language = C++

Under Code Information → Compiler flags → add:

-std=c++17


To generate FMU:

In the top bar, click Flash icon (near Save)

Select Standalone FMU

In the FMU Builder tab:

Click Refresh

In the Contents section, select Standalone FMU

Finally, click Create ✅

📄 Project Structure

├── ClearDiagnosticDTC.h          # Diagnostic service header
├── DID.h                         # Data Identifier definitions
├── DIDReadService.h              # Service for reading DID
├── DIDWriteService.h             # Service for writing DID
├── DTC.h                         # Diagnostic Trouble Code definitions
├── DTCReadService.h              # Service for reading DTC
├── ECUSensorData.h               # ECU sensor data structures
├── ECUService.h                  # Main ECU service header
├── ECUServiceFactory.h           # Factory for creating ECU services
├── ECUSIMLONK.slx                # Simulink model (ECU simulation logic)
├── FMECUService.slx              # FMU-compatible Simulink model
├── out.mat                       # MATLAB output data
├── README.md                     # Project documentation
├── Routine.h                     # Routine definitions
├── RoutineService.h              # Service for executing routines
├── rtwmakecfg.m                  # MATLAB build configuration script
├── SERVICEECU.c                  # C source for ECU
├── SERVICEECU.cpp                # ECU simulation source code
├── SERVICEECU.mexw64             # Compiled MEX file (Windows x64)
├── SERVICEECU.tlc                # Target Language Compiler file
├── SERVICEECU_wrapper.c          # Wrapper for MATLAB/Simulink integration (C)
├── SERVICEECU_wrapper.cpp        # Wrapper for MATLAB/Simulink integration (C++)
├── SERVICEECUsimlik.fmu          # Generated FMU for co-simulation
├── SERVICEECUsimlik.slx          # Simulink model for FMU export
├── SFB_SERVICEECU__SFB.mat       # Saved MATLAB/Simulink data
