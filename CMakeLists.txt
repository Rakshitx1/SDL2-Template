cmake_minimum_required(VERSION 3.10)

project(SDL2Template VERSION 1.0 LANGUAGES CXX)

# Set the build type to Debug by default if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

# Set the module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/")

# Find SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# List your source files
set(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
)

# Create an executable
add_executable(SDL2Template ${SOURCES})

# Set compiler flags for Debug
target_compile_options(SDL2Template PRIVATE $<$<CONFIG:DEBUG>: -O0 -g -Wall>)

# Set compiler flags for Release
target_compile_options(SDL2Template PRIVATE $<$<CONFIG:RELEASE>: -O3>)

# Link the executable with SDL2 libraries
target_link_libraries(SDL2Template PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
