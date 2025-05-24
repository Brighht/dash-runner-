cmake_minimum_required(VERSION 3.10)
project(dash-runner)

set(CMAKE_CXX_STANDARD 17)

# Add source files
file(GLOB SOURCES src/*.cpp)

# SFML setup
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Include headers
include_directories(src)

# Create executable
add_executable(dash-runner ${SOURCES})

# Link SFML
target_link_libraries(dash-runner sfml-graphics sfml-window sfml-system)
