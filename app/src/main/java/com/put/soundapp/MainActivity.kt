package com.put.soundapp

import android.graphics.Color
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    private val TAG: String = MainActivity::class.java.simpleName
    lateinit var playbackEngine: PlaybackEngine

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    fun clickEngineButton(view: View){
       var startNativeButton = findViewById<Button>(R.id.startEngineButton);
        Toast.makeText(applicationContext, "Nacisnieto przycisk", Toast.LENGTH_SHORT).show()
        startNativeButton.setBackgroundColor(Color.CYAN)
        playbackEngine = PlaybackEngine()
        playbackEngine.StartAudioEngine()
        startNativeButton.setBackgroundColor(Color.RED)
    }
}