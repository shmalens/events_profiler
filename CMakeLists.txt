cmake_minimum_required(VERSION 3.16)
project(Profiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(profiler project/main.cpp project/src/dispatcher_src/Dispatcher.cpp)
include_directories(project/include/profiler_lib_headers)
include_directories(project/include/dispatcher_headers)

add_library(profiler_lib STATIC project/src/profiler_lib/Date.cpp
                                project/src/profiler_lib/Events.cpp
                                project/src/profiler_lib/DataBase.cpp
                                project/src/profiler_lib/Exceptions.cpp)

target_link_libraries(profiler profiler_lib)
