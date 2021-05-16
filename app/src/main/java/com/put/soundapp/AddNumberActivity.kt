package com.put.soundapp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView

class AddNumberActivity : AppCompatActivity() {
    lateinit var audioEngine: AudioEngine
    lateinit var plusOneBtn: Button;
    lateinit var plusOneByTfBtn: Button;
    lateinit var numberTxt: TextView;
    lateinit var switchActivityBtn: Button;


    var number: Int = 0;
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_add_number)
        audioEngine = AudioEngine()
        var isEngineCreated = audioEngine.Create()

        plusOneBtn = findViewById<Button>(R.id.plusBtn);
        plusOneBtn.setOnClickListener({
            number = audioEngine.PlusOne();
            numberTxt.text = number.toString();
        })

        plusOneByTfBtn = findViewById<Button>(R.id.TFplusBtn);
        plusOneByTfBtn.setOnClickListener({
            number = audioEngine.PlusOneByTf();
            numberTxt.text = number.toString();
        })

        switchActivityBtn = findViewById<Button>(R.id.switchToRecordBtn);
        switchActivityBtn.setOnClickListener({
            val intent = Intent(this, MainActivity::class.java)
            startActivity(intent)
        })
        numberTxt = findViewById<TextView>(R.id.numberTxt);
    }
}