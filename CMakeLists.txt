cmake_minimum_required(VERSION 3.0)
project(RandomEngineProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main src/main.cpp src/engine.constructor.cpp src/engine.member.cpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)