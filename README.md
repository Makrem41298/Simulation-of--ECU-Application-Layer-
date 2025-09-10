🚗 Simulation of ECU Application Layer

This project simulates the ECU (Electronic Control Unit) application layer using MATLAB/Simulink with C++ integration and supports exporting models to FMU (Functional Mock-up Unit) for co-simulation.

⚙️ Requirements

MinGW-w64 Compiler (C/C++/Fortran)

Download: MATLAB Support for MinGW-w64

Install and configure it with MATLAB.

FMU Builder for Simulink

Download: FMU Builder for Simulink

Required for exporting models to FMU format.

MATLAB R2022 or later

Needed for full FMU Builder compatibility.

🛠️ Compilation with S-Function Builder

Place your source files inside the project:

SERVICEECU.cpp

SERVICEECU_wrapper.cpp

In MATLAB Command Window, run:

mex -R2018a CXXFLAGS="$CXXFLAGS -std=c++17" SERVICEECU.cpp SERVICEECU_wrapper.cpp


✅ This ensures the code is compiled with the C++17 standard.

🔄 Export to FMU in Simulink

Open your Simulink model.

Go to Modeling → Model Settings.

Under Simulation Target:

Set Language = C++.

Under Code Information → Compiler flags, add:

-std=c++17


To generate FMU:

Click the Flash icon (near Save).

Select Standalone FMU.

Open the FMU Builder tab:

Click Refresh.

In Contents, select Standalone FMU.

Click Create ✅.

📂 Project Structure
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
