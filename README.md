UAV Telemetry and Navigation Simulator

## How to Compile and Run

Follow these instructions to get a local copy of the project up and running on your machine.

### Prerequisites

Before you begin, ensure you have a complete C++ development toolchain installed.

* **On Windows**:
    The easiest way is to install [MSYS2](https://www.msys2.org/) and use its terminal to install the MinGW-w64 toolchain, which includes `g++` and `make`.
    ```bash
    # In the MSYS2 terminal
    pacman -S mingw-w64-x86_64-toolchain
    ```

* **On Debian/Ubuntu Linux**:
    You can install the `build-essential` package which includes `g++` and `make`.
    ```bash
    sudo apt update && sudo apt install build-essential
    ```

### Instructions

1.  **Clone the Repository**
    ```bash
    git clone [https://github.com/wasayr1/UAVTelemetry.git](https://github.com/wasayr1/UAVTelemetry.git)
    ```

2.  **Navigate to the Project Directory**
    ```bash
    cd UAVTelemetry
    ```

3.  **Compile the Project**
    Use the `make` command to compile the C++ source code using the provided Makefile.
    ```bash
    make
    ```
    *(Note: On some Windows MinGW installations, you may need to use the command `mingw32-make` instead.)*

4.  **Run the Application**
    * On Windows (in PowerShell or CMD):
        ```powershell
        .\simulator.exe
        ```
    * On Linux/macOS:
        ```bash
        ./simulator
        ```
