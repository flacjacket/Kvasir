cmake_minimum_required(VERSION 3.2)

project(Kvasir)

set(CMAKE_DEBUG_POSTFIX "d")

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(BUILD_TESTING 0)
add_subdirectory(third_party/mpl)

add_library(Kvasir INTERFACE)
target_include_directories(Kvasir INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Lib)
target_link_libraries(Kvasir INTERFACE kvasir_mpl)
target_compile_features(Kvasir INTERFACE cxx_std_17)
target_compile_options(Kvasir
                       INTERFACE
                       -Wall
                       -Wextra
                       -pedantic
                       -Wold-style-cast)

enable_testing()
add_executable(KvasirTest test/apply.cpp
                          test/usb.cpp
                          test/main.cpp)
target_link_libraries(KvasirTest PRIVATE Kvasir)

add_test(Kvasir KvasirTest)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/Lib
        DESTINATION .
        )
