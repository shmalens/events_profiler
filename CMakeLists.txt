cmake_minimum_required(VERSION 3.16)
project(Profiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(profiler project/main.cpp)
include_directories(project/include)

add_library(profiler_lib STATIC project/src/Date.cpp
                                project/src/Events.cpp)
target_link_libraries(profiler profiler_lib)