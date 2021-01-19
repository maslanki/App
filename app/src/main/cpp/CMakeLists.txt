cmake_minimum_required(VERSION 3.4.1)
project(soundApp LANGUAGES C CXX)

add_library(soundApp
        SHARED
        SampleClass.cpp
        AudioEngine.cpp)
set (OBOE_DIR ../../../../../oboe)
add_subdirectory(${OBOE_DIR} ./oboe)
include_directories(${OBOE_DIR}/include)

target_link_libraries(soundApp log oboe)