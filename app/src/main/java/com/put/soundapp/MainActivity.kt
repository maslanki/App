package com.put.soundapp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }
    fun clickEngineButton(view: View){
       var startNativeButton = findViewById<Button>(R.id.startEngineButton);
   // startNativeButton.text = "x"
       // Toast.makeText(M,"WORKS!",Toast.LENGTH_SHORT)
        var pe = PlaybackEngine();
        startNativeButton.text= pe.startNativeEngineFromKt();
    }

}