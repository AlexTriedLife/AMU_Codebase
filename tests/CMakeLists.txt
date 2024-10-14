enable_testing()
# Locate Google Test
include_directories(${GTEST_DIR}/include)

file(GLOB_RECURSE TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

set(INCLUDES ${CMAKE_SOURCE_DIR../include})
set(SOURCES ${CMAKE_SOURCE_DIR}/src)
# Add the executable for running tests

include_directories(
    ${Boost_INCLUDE_DIRS}
    ${OpenSSL_INCLUDE_DIRS}
    ${SDL_INCLUDE_DIRS}
    ${INCLUDE_DIR}
)
add_executable(runTests ${TEST_SOURCES} ${SOURCES}/note.cc ${SOURCES}/vector2.cc ${SOURCES}/wave.cc)

# Debugmsg
message(STATUS "Test sources: ${TEST_SOURCES}")
message(STATUS "sources: ${SOURCES}")

# Link test executable against Google Test and the shared library
target_link_libraries(runTests
    gtest
    gtest_main
    gmock
    gmock_main
    ${Boost_LIBRARIES}
    SDL3::SDL3
    SDL3_image::SDL3_image
    ${OPENSSL_LIBRARIES}
)
add_test(NAME runTests COMMAND runTests)