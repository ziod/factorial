cmake_minimum_required(VERSION 3.17)
project(factorial)

set(CMAKE_CXX_STANDARD 11)

file(GLOB sources_main "src/*.h" "src/*.cpp")
file(GLOB sources "src/**/*.h" "src/**/*.cpp")

add_executable(factorial ${sources_main} ${sources})