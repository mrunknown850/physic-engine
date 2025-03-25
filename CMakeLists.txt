cmake_minimum_required(VERSION 3.10)
project(Physics_sim)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory so we can use #include "file.hpp" cleanly
include_directories(
    common/include
    backend/include
    backend/include/physics
    frontend/include
)

# Collect all backend source files
file(GLOB_RECURSE BACKEND_SOURCES
"backend/src/main.cpp"
"backend/src/physics/Forces.cpp"
"backend/src/physics/Math.cpp"
"backend/src/physics/PhysicsEngine.cpp"
"backend/src/physics/RigidBody.cpp"
)

# Create the backend executable
add_executable(backend_app ${BACKEND_SOURCES})
