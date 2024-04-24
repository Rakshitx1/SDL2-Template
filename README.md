# SDL2 Template

> [!NOTE]
> This template is specifically tailored for SDL2 development on Linux systems.

This repository comes pre-configured with basic setup and build scripts to get you up and running quickly.

## Prerequisites

Before using this template, ensure you have the following prerequisites installed on your system:

- CMake (version 3.10 or higher)
- SDL2 development libraries
- SDL2_image development libraries

You can install SDL2 and SDL2_image on Debian-based systems (like Ubuntu) using:

```bash
sudo apt-get update
sudo apt-get install libsdl2-dev libsdl2-image-dev
```

## Usage

### 1. Clone the Repository

Clone this repository to your local machine using Git:

```bash
git clone https://github.com/rakshitx1/SDL2-Template.git
```

### 2. Build and Run

Navigate into the cloned repository and execute the build script `build.sh`:

```bash
cd SDL2-Template
./build.sh
```

This script will build the project in Debug mode and automatically run the generated executable. If you prefer to build in Release mode for optimized performance, use:

```bash
./build.sh release
```
