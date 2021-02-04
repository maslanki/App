cmake_minimum_required(VERSION 3.4.1)
project(soundApp LANGUAGES C CXX)

add_library(audioEngine
        SHARED
        AudioEngine.cpp
        jni-bridge.cpp)

set (OBOE_DIR ../../../../../oboe)
add_subdirectory(${OBOE_DIR} ./oboe)
include_directories(${OBOE_DIR}/include)

target_link_libraries(audioEngine log oboe)