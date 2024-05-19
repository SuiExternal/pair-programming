cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(KVStoreProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(main src/main.cpp)

# Include directories
target_include_directories(main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )