cmake_minimum_required(VERSION 3.4.1)
project(soundApp LANGUAGES C CXX)

add_library(audioEngine
        SHARED
        AudioEngine.cpp
        RecordingCallback.cpp
        PlayingCallback.cpp
        SoundRecording.cpp
        Calculator.cpp
        jni-bridge.cpp)

set (OBOE_DIR ../../../../../oboe)
add_subdirectory(${OBOE_DIR} ./oboe)
include_directories(${OBOE_DIR}/include)
set(LIB_SND_FILE_DIR ../../../../libsndfile)
add_subdirectory(${LIB_SND_FILE_DIR} ./sndfile)
include_directories(${LIB_SND_FILE_DIR}/src)
target_link_libraries(audioEngine ${log-lib} oboe sndfile)