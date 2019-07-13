cmake_minimum_required(VERSION 3.1)

project(Kvasir)

find_package(kvasir_mpl REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

option(ENABLE_CLANG_TIDY "Enable testing with clang-tidy" FALSE)

if(ENABLE_CLANG_TIDY)
    find_program(CLANGTIDY clang-tidy REQUIRED)
    set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY})
endif()

add_library(kvasir_sfr INTERFACE)
target_link_libraries(kvasir_sfr INTERFACE kvasir_mpl)
target_compile_features(kvasir_sfr INTERFACE cxx_std_17)
target_include_directories(kvasir_sfr INTERFACE src)

enable_testing()
add_subdirectory(tests)
