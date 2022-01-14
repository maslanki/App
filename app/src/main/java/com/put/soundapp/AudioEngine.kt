
package com.put.soundapp
import android.util.Log

class AudioEngine {
    private val TAG: String = AudioEngine::class.java.simpleName
    init {
        System.loadLibrary("soundApp")
    }
    external fun Create() : Boolean
    external fun StartRecording();
    external fun StopRecording();
    external fun PlusOne() : Int;
    external fun PlusOneByTf() : Int;
}
