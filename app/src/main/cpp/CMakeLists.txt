cmake_minimum_required(VERSION 3.4.1)
project(soundApp LANGUAGES C CXX)

get_filename_component(SAMPLE_ROOT_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../.. ABSOLUTE)

set (OBOE_DIR ../../../../../oboe)
add_subdirectory(${OBOE_DIR} ./oboe)
include_directories(${OBOE_DIR}/include)

add_library(soundApp
        SHARED
        AudioEngine.cpp
        RecordingCallback.cpp
        PlayingCallback.cpp
        SoundRecording.cpp
        Calculator.cpp
        jni-bridge.cpp)

set(LIB_SND_FILE_DIR ../../../../libsndfile)
add_subdirectory(${LIB_SND_FILE_DIR} ./sndfile)
include_directories(${LIB_SND_FILE_DIR}/src)

set(JNI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../jni)

add_library(tflite-lib SHARED IMPORTED)
set_target_properties(tflite-lib
       PROPERTIES IMPORTED_LOCATION
        ${JNI_DIR}/${ANDROID_ABI}/libtensorflowlite_jni.so)
include_directories( ${JNI_DIR} )




target_link_libraries(soundApp
        tflite-lib
        ${log-lib}
        oboe
        sndfile)


