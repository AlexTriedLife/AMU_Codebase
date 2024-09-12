cmake_minimum_required(VERSION 3.20)

project(AMU_Codebase)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define directories
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

# Set Boost root and find Boost libraries
set(BOOST_ROOT "D:/Libraries/C++/boost_1_85_0")
set(CMAKE_PREFIX_PATH "${BOOST_ROOT}/stage/lib/cmake/Boost-1.85.0")
find_package(Boost 1.85 REQUIRED COMPONENTS filesystem)

# Download GoogleTest as part of the build process
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# Prevent overriding the parent project's compiler settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Include directories
include_directories(
    ${Boost_INCLUDE_DIRS}
    ${OpenSSL_INCLUDE_DIRS}
    ${INCLUDE_DIR}
)

# Find source files
file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cc)

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})


# Link libraries to the executable
target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    GTest::gtest
    GTest::gtest_main
    ${OpenSSL_LIBRARIES}
)

# Enable testing
enable_testing()

# Add tests
add_subdirectory(${TEST_DIR})

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
