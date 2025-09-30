add_library(winterval STATIC Winterval.cpp Winterval.hpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../out/)
# Uncomment for sanity tests
#add_executable(win_test main.cpp)
#target_link_libraries(win_test winterval)