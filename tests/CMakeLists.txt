find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(COMPILE_OPTIONS
    -Wall
    -Wextra
    -Werror
    -pedantic
    -Wold-style-cast)

set(TEST_FILES
    main.cpp)

add_executable(kvasir_test ${TEST_FILES})
target_link_libraries(kvasir_test PRIVATE kvasir_sfr)
target_link_libraries(kvasir_test PRIVATE ${GTEST_BOTH_LIBRARIES})
target_compile_options(kvasir_test PRIVATE ${COMPILE_OPTIONS})
add_test(kvasir_test kvasir_test)
