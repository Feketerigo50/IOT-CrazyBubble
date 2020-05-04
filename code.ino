#include <SoftwareSerial.h>
#include <Wire.h>
#include "pitches.h"
#include <Tone.h>

int LED = 12;
SoftwareSerial I2CBT(10,11);
Tone toneLeft;
Tone toneRight;
int music = 0;
int durationLeft;
int durationRight;
int pauseBetweenNote;
//小星星的音階 (左聲道)
int starLeft[]={NOTE_C4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4, \
                NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4, \
                NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4, \  
                NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_D4, \           
                NOTE_C4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4, \
                NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_E4,NOTE_C4};

//每個音階的長度 (左聲道)
int beatLeft[]={4,4,4,4,  4,4,2,   \
                4,4,4,4,  4,4,2,   \
                4,4,4,4,  4,4,2,   \
                4,4,4,4,  4,8,8,4,4,  \
                4,4,4,4,  4,4,2,   \
                4,4,4,4,  4,8,8,2};

//小星星的音階 (右聲道)
int starRight[]={NOTE_C3,NOTE_C3,NOTE_E3,NOTE_E3,NOTE_F3,NOTE_F3,NOTE_E3, \
                 NOTE_D3,NOTE_D3,NOTE_C3,NOTE_C3,NOTE_F3,NOTE_G3,NOTE_E3, \
                 NOTE_E3,NOTE_E3,NOTE_D3,NOTE_D3,NOTE_C3,NOTE_C3,NOTE_B2, \
                 NOTE_E3,NOTE_E3,NOTE_D3,NOTE_D3,NOTE_C3,NOTE_C3,NOTE_C3,NOTE_C3,NOTE_B2, \             
                 NOTE_C3,NOTE_C3,NOTE_E3,NOTE_E3,NOTE_F3,NOTE_F3,NOTE_E3, \
                 NOTE_D3,NOTE_D3,NOTE_C3,NOTE_C3,NOTE_F3,NOTE_G3,NOTE_G3,NOTE_E3};

//每個音階的長度
int beatRight[]={4,4,4,4,  4,4,2,  \
             4,4,4,4,  4,4,2,   \
             4,4,4,4,  4,4,2,   \
             4,4,4,4,  4,8,8,4,4,  \
             4,4,4,4,  4,4,2,   \
             4,4,4,4,  4,8,8,2};

void setup() {
  ///
  toneLeft.begin(9);
  toneRight.begin(8);
  ///
  pinMode(3, OUTPUT);  // 設定D3為輸出腳位，控制馬達旋轉方向  
  pinMode(4, OUTPUT);  // 設定D4為輸出腳位，控制馬達旋轉與否
  digitalWrite(3, LOW); // 設定馬達旋轉方向為逆時針方向
  ///
  Serial.begin(9600);
  I2CBT.begin(9600);
  pinMode(LED, OUTPUT);    
}

void loop() {
  byte cmmd[20];
  int insize;
  while(1){
    if ((insize=(I2CBT.available()))>0){
      for (int i=0; i<insize; i++){
        Serial.print(cmmd[i]=char(I2CBT.read()));
        Serial.print("\n"); 
      }
    }
    switch (cmmd[0]) {
    case 'S':
      digitalWrite(LED,HIGH);
      //
      analogWrite(5,210);   // 吹泡桿
      digitalWrite(4,HIGH); // 葉片
      //
      durationLeft = 1000/beatLeft[music];    //左聲道每個音的撥放時間
      durationRight = 1000/beatRight[music];  //右聲道每個音的撥放時間
      toneLeft.play(starLeft[music], durationLeft);  //撥放左聲道
      toneRight.play(starRight[music],durationRight);  //撥放右聲道
      pauseBetweenNote=durationLeft * 1.15;  //設定每個音中間的間隔
      delay(pauseBetweenNote);
      music = music + 1;
      //
      break;  

    case 'E':
      digitalWrite(LED,LOW);
      digitalWrite(4, LOW);
      break;
    }
    if( music == 44 ){
      music = 0;
    }
  }
}
