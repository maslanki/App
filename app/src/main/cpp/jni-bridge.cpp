#include <jni.h>
#include "AudioEngine.h"

AudioEngine *audioEngine = nullptr; //nie jestem pewna czy to nie musi być static
//ale statici są niebezpieczne wiec sprobujmy bez na razie

//most między cpp i kotlin
extern "C"{
JNIEXPORT jboolean JNICALL
Java_com_put_soundapp_AudioEngine_Create(  JNIEnv *env, jobject obj){
    if (audioEngine == nullptr) {
        audioEngine = new AudioEngine();
    }
    return (audioEngine != nullptr);
}

JNIEXPORT void JNICALL
Java_com_put_soundapp_AudioEngine_StartRecording(  JNIEnv *env, jobject obj){
    if (audioEngine != nullptr) {
        audioEngine->startRecording();
    }
}

JNIEXPORT void JNICALL
Java_com_put_soundapp_AudioEngine_StopRecording(  JNIEnv *env, jobject obj){
    if (audioEngine != nullptr) {
        audioEngine->stopRecording();
    }
}
}