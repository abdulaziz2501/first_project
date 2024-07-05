#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <IRremote.h>

# define Start_Byte    0x7E
# define Version_Byte  0xFF
# define command_Length 0x06
# define End_Byte      0xEF
# define Acknowledge   0x00
//--------------------------------------------------------//
// masofaviy pultdan kelayotgan kodlarni kiriting

# define pause_play      69
# define next_song       21
# define prev_song        7
# define vol_inc         25
# define vol_dec         22
# define one             12
# define two             24
# define three           94
# define four             8
# define five            28
# define six             90
# define seven           66
# define eight           82
# define nine            74
# define zero            13
# define mute            71     // pultdan kelayotgan command kodlari


SoftwareSerial aloqa_uzatish(10, 11); // RX, TX
DFRobotDFPlayerMini aloqa;
void printDetail(uint8_t type, int value);
boolean Playing = false;
#define malumot_almashish A0
             // {0,0,0,0,0,0},{0,0,0,0,0,1},{0,0,0,0,1,0},{0,0,0,0,1,1},{0,0,0,1,0,0},{0,0,0,1,0,1},{0,0,0,1,1,0},{0,0,0,1,1,1}, yonuvchi chiroqlar uchun demultipleksor uchun kodlar(binary) ko'rinishida
int led[64][6]={{0,0,0,0,0,0},{0,0,0,0,0,1},{0,0,0,0,1,0},{0,0,0,0,1,1},{0,0,0,1,0,0},{0,0,0,1,0,1},{0,0,0,1,1,0},{0,0,0,1,1,1},
                {0,0,1,0,0,0},{0,0,1,0,0,1},{0,0,1,0,1,0},{0,0,1,0,1,1},{0,0,1,1,0,0},{0,0,1,1,0,1},{0,0,1,1,1,0},{0,0,1,1,1,1},
                {0,1,0,0,0,0},{0,1,0,0,0,1},{0,1,0,0,1,0},{0,1,0,0,1,1},{0,1,0,1,0,0},{0,1,0,1,0,1},{0,1,0,1,1,0},{0,1,0,1,1,1},
                {0,1,1,0,0,0},{0,1,1,0,0,1},{0,1,1,0,1,0},{0,1,1,0,1,1},{0,1,1,1,0,0},{0,1,1,1,0,1},{0,1,1,1,1,0},{0,1,1,1,1,1},
                {1,0,0,0,0,0},{1,0,0,0,0,1},{1,0,0,0,1,0},{1,0,0,0,1,1},{1,0,0,1,0,0},{1,0,0,1,0,1},{1,0,0,1,1,0},{1,0,0,1,1,1},
                {1,0,1,0,0,0},{1,0,1,0,0,1},{1,0,1,0,1,0},{1,0,1,0,1,1},{1,0,1,1,0,0},{1,0,1,1,0,1},{1,0,1,1,1,0},{1,0,1,1,1,1},
                {1,1,0,0,0,0},{1,1,0,0,0,1},{1,1,0,0,1,0},{1,1,0,0,1,1},{1,1,0,1,0,0},{1,1,0,1,0,1},{1,1,0,1,1,0},{1,1,0,1,1,1},
                {1,1,1,0,0,0},{1,1,1,0,0,1},{1,1,1,0,1,0},{1,1,1,0,1,1},{1,1,1,1,0,0},{1,1,1,1,0,1},{1,1,1,1,1,0},{1,1,1,1,1,1}}; 
                
                

void setup()
{
  aloqa_uzatish.begin(9600);
  Serial.begin(9600);
  if (!aloqa.begin(aloqa_uzatish)) {  //mp3 bilan bog'lanish uchun SoftwareSerialdan foydalanish.
    Serial.println(F("Aloqaga ulanib bo'lmayabdi: "));
    while(true);
  }
  for(int i=2; i<8;i++){
    pinMode(i, OUTPUT);
  }

  
  IrReceiver.begin(malumot_almashish); 
  aloqa.play(1);
  Playing = true;
  Serial.println(F("Aloqadagi qurilma online holatda:"));
  
  aloqa.setTimeOut(500); // Aloqani o'tishini 500 ms ga sozlash
  
  //----Ovoz sozlamasi----
  aloqa.volume(25);  //ovoz qiymatini sozlash (0~30).  
  //----equalazer sozlamasi----
  aloqa.EQ(DFPLAYER_EQ_NORMAL); // equalazer o'rtachaga sozlangan
  
  //----SD micro flash dan foydalanish sozlamasi----
  aloqa.outputDevice(DFPLAYER_DEVICE_SD);
}
int a=1;
void loop()
{
  if(IrReceiver.decode())
 {
  IrReceiver.resume();
  int command = IrReceiver.decodedIRData.command;
  Serial.println(command);
  delay(200);// Bu yerda masofaviy pultdan kelayotgan signalni 'command' degan o'zgaruvchiga yozib un
  i chiqaradi.


  if (command==pause_play)
  {
   if(Playing)
   {
    aloqa.pause();
    Playing = false;
    delay(200);
   }   
   else
   {
    Playing = true;
    aloqa.start();
    delay(200);
   }  
  }  
  if (command==next_song)
  {
   if(Playing)
   {
    a++;
    aloqa.playMp3Folder(a);
    delay(200);
   }
   else{
   }
   delay(200);
  }
  if (command==prev_song)
  {
   if(Playing)
   {
    a--;    
    aloqa.playMp3Folder(a);
    delay(200);
   }
   else{
   }   
   delay(200);
  }

  if (command==zero)
  {
   if(Playing)
   {
    a=62;
    aloqa.playMp3Folder(a);
    delay(200);
   }
   else{
   }
   delay(200);
  }

  if (command==one)
  {
   if(Playing)
   {
    a=1;
    aloqa.playMp3Folder(a);
    delay(200);
   }
   else{
   }
   delay(200);
  }


  if (command==two)
  {
   if(Playing)
   {
    a=15;
    aloqa.playMp3Folder(a);
    delay(200);
   }
   else{
   }
   delay(200);
  }

  
  if (command==three)
  {
   if(Playing)
   {
    a=21;
    aloqa.playMp3Folder(a);
    delay(200);
   }
   else{
   }
   delay(200);
  }

  
  if (command==four)
  {
   if(Playing)
   {
    a=31;
    aloqa.playMp3Folder(a);
    delay(200);
   }
   else{
   }
   delay(200);
  }

  
  if (command==five)
  {
   if(Playing)
   {
    a=44;
    aloqa.playMp3Folder(a);
    delay(200);
   }
   else{
   }
   delay(200);
  }

  if(command==vol_inc)
  {
  aloqa.volumeUp(); //Volume Up
  }
  if(command==vol_dec)
  {
   aloqa.volumeDown(); //Volume Down
  }
   IrReceiver.resume();
 }

 if (a==1){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

  if (a==2){
    if(Playing){
    for(int i=0; i<13; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
  }



 if (a==3){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==4){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==5){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==6){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==7){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==8){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==9){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==10){
    if(Playing){
    for(int i=0; i<32; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==11){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==12){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==13){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==14){
    if(Playing){
    for(int i=0; i<12; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==15){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==16){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==17){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==18){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==19){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==20){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==21){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==22){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==23){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==24){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==25){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==26){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==27){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==28){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==29){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==30){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==31){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==32){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==33){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==34){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==35){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==36){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==37){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==38){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==39){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==40){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==41){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==42){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==43){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==44){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==45){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==46){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==47){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==48){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==49){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==50){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==51){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

  if (a==52){
    if(Playing){
    for(int i=0; i<13; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
  }



 if (a==53){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==54){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==55){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==56){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==57){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==58){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==59){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if (a==60){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
  }

 if (a==61){
    if(Playing){
    for(int i=0; i<2; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
  }



 if (a==62){
    if(Playing){
    for(int i=0; i<32; i++){
          for(int j=2; j<8; j++){
          digitalWrite(j, led[a][j-2]);
          }
          delay(500);
          for(int k=2; k<8; k++){
          digitalWrite(k, LOW);
          }
          delay(500);
        }
    }
    else{
      for(int i=2; i<8; i++){
        digitalWrite(i, LOW);
      }
    }
    delay(200);
   }

 if(a>63)a=1;
 if(a>=2){
  for(int i=2; i<8;i++){
    digitalWrite(i, led[a-2][i-2]);
  }
  
 }
 else{
  for(int i=2; i<8;i++){
    digitalWrite(i, 0);
  }
 }


}