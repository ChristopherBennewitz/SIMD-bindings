cmake_minimum_required(VERSION 3.16)
project(Simd-bindings LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(test_simd test_simd.cpp)

target_compile_options(test_simd PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-mavx2 -O2>
    $<$<CXX_COMPILER_ID:MSVC>:/arch:AVX2 /O2>
)
