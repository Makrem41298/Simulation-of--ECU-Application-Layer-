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

SERVICEECU.cpp → ECU simulation source code

SERVICEECU_wrapper.cpp → Wrapper for MATLAB/Simulink integration

README.md → Documentation (this file)

fmu/ → Generated FMU files