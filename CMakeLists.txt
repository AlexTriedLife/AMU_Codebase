cmake_minimum_required(VERSION 3.20)

project(AMU_Codebase)


# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define directories
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

set(BOOST_ROOT "D:/Libraries/C++/boost_1_85_0")
set(Boost_NO_SYSTEM_PATHS TRUE)

# Set the CMake prefix path for Boost
set(CMAKE_PREFIX_PATH "${BOOST_ROOT}/stage/lib/cmake/Boost-1.85.0")

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
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
# Find source files
file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})



# Include directories
target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${OpenSSL_INCLUDE_DIRS}
    
    ${SDL_INCLUDE_DIRS}
    ${INCLUDE_DIR}
)

# Link libraries to the executable
target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    SDL3::SDL3
    SDL3_image::SDL3_image
    gtest
    gtest_main
    gmock
    gmock_main
    ${OpenSSL_LIBRARIES}
)

# Enable testing
enable_testing()

# Add tests
add_subdirectory(${TEST_DIR})

