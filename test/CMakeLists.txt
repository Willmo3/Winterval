find_package(GTest CONFIG REQUIRED)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../out/tests)

add_executable(test_winterval test_winterval.cpp)
target_link_libraries(test_winterval winterval GTest::gtest_main)
include(GoogleTest)
