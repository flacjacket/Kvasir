cmake_minimum_required(VERSION 3.1)

project(Kvasir)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

find_program(CLANGTIDY clang-tidy REQUIRED)
set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY})

add_library(kvasir_sfr INTERFACE)
target_compile_features(kvasir_sfr INTERFACE cxx_std_17)
target_include_directories(kvasir_sfr INTERFACE src)

enable_testing()
add_subdirectory(tests)
