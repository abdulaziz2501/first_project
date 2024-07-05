#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <IRremote.h>

# define Start_Byte   0x7E
# define Version_Byte  0xFF
# define Command_Length 0x06
# define End_Byte    0xEF
# define Acknowledge  0x00
//--------------------------------------------------------//
// REPLACE THESE HEX CODES WITH YOUR REMOTE BUTTON CODES

# define pause_play      28
# define one              8
# define two             78
# define three            2
# define four            30
# define five            88
# define six             87
# define seven           20
# define eight            3
# define nine            29
# define ten             86
# define eleven          67
# define twelve          66
# define three_ten       65
# define four_ten         1
# define five_ten        70
# define six_ten         25
# define seven_ten       64
# define eight_ten       26
# define nine_ten        23
# define twenty          71
# define twenty_one       6
# define twenty_two       7
# define twenty_three    24
# define twenty_four     72
# define twenty_five     10
# define twenty_six      92
# define twenty_seven    27
# define twenty_eight    69
# define twenty_nine      9
# define thirty          75
# define thirty_one       5
# define thirty_two      79
# define thirty_three    84
# define thirty_four     22
# define thirty_five     21
# define thirty_six      80
# define thirty_seven    18
# define thirty_eight    17
# define thirty_nine     76
# define forty           14
# define forty_one       13
# define forty_two       73
# define forty_three     12
# define forty_four      16
# define forty_five      93
# define forty_six       89
# define forty_seven     81
# define forty_eight     85

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);
boolean Playing = false;
#define IR_RECEIVE_PIN A0
  // {0,0,0,0,0,0},{0,0,0,0,0,1},{0,0,0,0,1,0},{0,0,0,0,1,1},{0,0,0,1,0,0},{0,0,0,1,0,1},{0,0,0,1,1,0},{0,0,0,1,1,1},
int led[63][6]={{0,0,0,0,0,1},{0,0,0,0,1,0},{0,0,0,0,1,1},{0,0,0,1,0,0},{0,0,0,1,0,1},{0,0,0,1,1,0},{0,0,0,1,1,1},
                {0,0,1,0,0,0},{0,0,1,0,0,1},{0,0,1,0,1,0},{0,0,1,0,1,1},{0,0,1,1,0,0},{0,0,1,1,0,1},{0,0,1,1,1,0},{0,0,1,1,1,1},
                {0,1,0,0,0,0},{0,1,0,0,0,1},{0,1,0,0,1,0},{0,1,0,0,1,1},{0,1,0,1,0,0},{0,1,0,1,0,1},{0,1,0,1,1,0},{0,1,0,1,1,1},
                {0,1,1,0,0,0},{0,1,1,0,0,1},{0,1,1,0,1,0},{0,1,1,0,1,1},{0,1,1,1,0,0},{0,1,1,1,0,1},{0,1,1,1,1,0},{0,1,1,1,1,1},
                {1,0,0,0,0,0},{1,0,0,0,0,1},{1,0,0,0,1,0},{1,0,0,0,1,1},{1,0,0,1,0,0},{1,0,0,1,0,1},{1,0,0,1,1,0},{1,0,0,1,1,1},
                {1,0,1,0,0,0},{1,0,1,0,0,1},{1,0,1,0,1,0},{1,0,1,0,1,1},{1,0,1,1,0,0},{1,0,1,1,0,1},{1,0,1,1,1,0},{1,0,1,1,1,1},
                {1,1,0,0,0,0},{1,1,0,0,0,1},{1,1,0,0,1,0},{1,1,0,0,1,1},{1,1,0,1,0,0},{1,1,0,1,0,1},{1,1,0,1,1,0},{1,1,0,1,1,1},
                {1,1,1,0,0,0},{1,1,1,0,0,1},{1,1,1,0,1,0},{1,1,1,0,1,1},{1,1,1,1,0,0},{1,1,1,1,0,1},{1,1,1,1,1,0},{1,1,1,1,1,1}};
void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    while(true);
  }
  for(int i=2; i<8;i++){
    pinMode(i, OUTPUT);
  }

  
  IrReceiver.begin(IR_RECEIVE_PIN); 
  myDFPlayer.play(1);
  Playing = true;
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms
  
  //----Set volume----
  myDFPlayer.volume(30);  //Set volume value (0~30).  
  //----Set different EQ----
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  
  //----Set device we use SD as default----
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
}
void loop(){
  if(IrReceiver.decode()){
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    Serial.println(command);// Here you can get your remote's buttons codes
    if (command==pause_play){
      if(Playing){
        myDFPlayer.pause();
        Playing = false;
        delay(200);
      }   
      else{
        Playing = true;
        myDFPlayer.start();
        delay(200);
      }  
    }

    
    if (command==one){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(1);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[0][j-2]);
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

    if (command==two){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(2);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[1][j-2]);
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

    if (command==three){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(3);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[2][j-2]);
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

    if (command==four){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(4);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[3][j-2]);
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

    if (command==five){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(5);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[4][j-2]);
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

    if (command==six){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(6);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[5][j-2]);
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

    if (command==seven){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(7);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[6][j-2]);
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

    if (command==eight){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(8);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[7][j-2]);
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

    if (command==nine){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(9);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[8][j-2]);
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

    if (command==ten){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(10);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[9][j-2]);
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

    if (command==eleven){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(11);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[10][j-2]);
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

    if (command==twelve){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(12);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[11][j-2]);
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

    if (command==three_ten){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(13);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[12][j-2]);
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
    if (command==four_ten){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(14);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[13][j-2]);
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

    if (command==five_ten){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(15);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[14][j-2]);
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

    if (command==six_ten){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(16);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[15][j-2]);
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

    if (command==seven_ten){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(17);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[16][j-2]);
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

    if (command==eight_ten){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(18);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[17][j-2]);
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

    if (command==nine_ten){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(19);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[18][j-2]);
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

    if (command==twenty){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(20);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[19][j-2]);
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



    if (command==twenty_one){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(21);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[20][j-2]);
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

    if (command==twenty_two){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(22);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[21][j-2]);
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

    if (command==twenty_three){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(23);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[22][j-2]);
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

    if (command==twenty_four){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(24);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[23][j-2]);
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

    if (command==twenty_five){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(25);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[24][j-2]);
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

    if (command==twenty_six){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(26);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[25][j-2]);
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

    if (command==twenty_seven){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(27);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[26][j-2]);
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

    if (command==twenty_eight){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(28);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[27][j-2]);
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

    if (command==twenty_nine){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(29);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[28][j-2]);
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

    if (command==thirty){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(30);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[29][j-2]);
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


    if (command==thirty_one){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(31);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[30][j-2]);
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
    if (command==thirty_two){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(32);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[31][j-2]);
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

    if (command==thirty_three){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(33);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[32][j-2]);
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

    if (command==thirty_four){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(34);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[33][j-2]);
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

    if (command==thirty_five){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(35);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[34][j-2]);
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

    if (command==thirty_six){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(36);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[35][j-2]);
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

    if (command==thirty_seven){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(37);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[36][j-2]);
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

    if (command==thirty_eight){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(38);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[37][j-2]);
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

    if (command==thirty_nine){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(39);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[38][j-2]);
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
    if (command==forty){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(40);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[39][j-2]);
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
    if (command==forty_one){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(41);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[40][j-2]);
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

    if (command==forty_two){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(42);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[41][j-2]);
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

    if (command==forty_three){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(43);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[42][j-2]);
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

    if (command==forty_four){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(44);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[43][j-2]);
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

    if (command==forty_five){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(45);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[44][j-2]);
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

    if (command==forty_six){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(46);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[45][j-2]);
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

    if (command==forty_seven){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(47);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[46][j-2]);
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

    if (command==forty_eight){
    if(Playing)
    {
      myDFPlayer.playMp3Folder(48);
        for(int i=0; i<6; i++)
        {
          for(int j=2; j<8; j++){
          digitalWrite(j, led[47][j-2]);
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
  }
  IrReceiver.resume();
}