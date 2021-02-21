package com.put.soundapp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    private val TAG: String = MainActivity::class.java.simpleName
    lateinit var audioEngine: AudioEngine

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        audioEngine = AudioEngine()
        audioEngine.Create()

        val startBtn : Button = findViewById<Button>(R.id.startRecordingButton);
        startBtn.setOnClickListener { startRecording(startBtn); }

        val stopBtn : Button = findViewById<Button>(R.id.stopRecordingButton);
        stopBtn.setOnClickListener { stopRecording(startBtn); }
    }

    private fun startRecording(startBtn: Button ){
        Toast.makeText(applicationContext, "Nagrywanie rozpoczęte", Toast.LENGTH_SHORT).show()
        startBtn.text = "Recording...";
        startBtn.isEnabled = false;
        audioEngine.StartRecording()
    }

    private fun stopRecording(startBtn: Button){
       startBtn.isEnabled = true;
        audioEngine.StopRecording()
    }
}