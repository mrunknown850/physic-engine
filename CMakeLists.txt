set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")  # Ensure debug symbols are included

cmake_minimum_required(VERSION 3.10)
project(Physics_sim)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# FetchContent_MakeAvailable(googletest)

# Add include directories
include_directories(
    common/include
    backend/include
    backend/include/physics
    frontend/include
)

# Collect all backend source files
file(GLOB_RECURSE BACKEND_SOURCES
    "backend/src/physics/*.cpp"
)

# Create the backend executable
add_executable(backend_app ${BACKEND_SOURCES} "backend/src/main.cpp")

# -----------------------
# Google Test Integration (System-wide Installation)
# -----------------------
enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE TEST_SOURCES
    "backend/tests/*.cpp"
)

add_executable(
  run_test
  ${TEST_SOURCES}
  ${BACKEND_SOURCES}
)
find_package(GTest REQUIRED)

target_link_libraries(
    run_test
    GTest::GTest
    GTest::Main
    pthread
)


include(GoogleTest)
gtest_discover_tests(run_test)
