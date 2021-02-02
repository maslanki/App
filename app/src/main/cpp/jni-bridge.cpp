#include <jni.h>
#include "AudioEngine.h"

//most między cpp i kotlin
extern "C"{
JNIEXPORT void JNICALL
Java_com_put_soundapp_PlaybackEngine_InitializeEngine(  JNIEnv *env,jobject obj){
    AudioEngine *audioEngine = new(std::nothrow) AudioEngine();
    audioEngine->Start();
}
}