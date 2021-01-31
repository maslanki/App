#include <jni.h>
#include "AudioEngine.h"

//most między cpp <=> kotlin
extern "C"{
JNIEXPORT void JNICALL
Java_com_put_soundapp_PlaybackEngine_InitializeEngine(JNIEnv* env, jobject thiz){
    AudioEngine* audioEngine = new(std::nothrow) AudioEngine();
    //  audioEngine->Start();
}
}