find_package(GTest REQUIRED)

set(COMPILE_OPTIONS
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wold-style-cast
    -Wcast-align
    -Wunused
    # -Wconversion
    -Wsign-conversion
    -Werror)

set(MY_INCS ${GTEST_INCLUDE_DIRS} CACHE STRING "gtest includes")

add_executable(kvasir_test write_constant_tests.cpp
                           write_runtime_tests.cpp
                           write_mixed_tests.cpp
                           write_value_tests.cpp)
target_link_libraries(kvasir_test PRIVATE kvasir_sfr)
target_link_libraries(kvasir_test PRIVATE GTest::GTest GTest::Main)
target_include_directories(kvasir_test PRIVATE .)
target_compile_options(kvasir_test PRIVATE ${COMPILE_OPTIONS})
add_test(kvasir_test kvasir_test)
