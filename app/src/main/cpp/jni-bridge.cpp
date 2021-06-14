#include <jni.h>
#include "AudioEngine.h"
#include "Calculator.h"

AudioEngine *audioEngine = nullptr; //nie jestem pewna czy to nie musi być static
Calculator *calculator = new Calculator();

//most między cpp i kotlin
extern "C" {
JNIEXPORT jboolean JNICALL
Java_com_put_soundapp_AudioEngine_Create(JNIEnv *env, jobject obj) {
    if (audioEngine == nullptr) {
        audioEngine = new AudioEngine();
    }
    return (audioEngine != nullptr);
}

JNIEXPORT void JNICALL
Java_com_put_soundapp_AudioEngine_StartRecording(JNIEnv *env, jobject obj) {
    if (audioEngine != nullptr) {
        audioEngine->startRecording();
    }
}

JNIEXPORT void JNICALL
Java_com_put_soundapp_AudioEngine_StopRecording(JNIEnv *env, jobject obj) {
    if (audioEngine != nullptr) {
        audioEngine->stopRecording();
    }
}

JNIEXPORT int JNICALL
Java_com_put_soundapp_AudioEngine_PlusOne(JNIEnv *env, jobject obj) {
    return calculator->plusOne();
}
JNIEXPORT int JNICALL
Java_com_put_soundapp_AudioEngine_PlusOneByTf(JNIEnv *env, jobject obj) {
    return calculator->plusOneByTensorFlow();
}
}