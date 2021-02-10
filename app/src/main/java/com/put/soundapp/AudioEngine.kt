//klasa tymczasowa do komunikacji C++ <=> kotlin

package com.put.soundapp
import android.util.Log

class AudioEngine {
    private val TAG: String = AudioEngine::class.java.simpleName
    init {
        System.loadLibrary("audioEngine")
    }
    external fun Create() : Boolean
}
