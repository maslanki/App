//klasa tymczasowa do komunikacji C++ <=> kotlin

package com.put.soundapp
import android.util.Log

class PlaybackEngine {
    private val TAG: String = PlaybackEngine::class.java.simpleName
    private external fun InitializeEngine()

    init {
        System.loadLibrary("audioEngine")
    }

    fun StartAudioEngine(){
        Log.d(TAG,"Uruchamianie silnika")
        InitializeEngine()
        Log.d(TAG,"Silnik uruchomiony?")
    }
}
