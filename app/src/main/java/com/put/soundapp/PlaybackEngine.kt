package com.put.soundapp

import android.content.Context
import android.media.AudioManager
import android.os.Build

public class PlaybackEngine {
    external fun startNativeEngine() : Unit
    fun startNativeEngineFromKt(): String{
    startNativeEngineFromKt();
        return "success"
    }
}