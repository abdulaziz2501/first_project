int birinchi=7;
int ikkinchi=8;
int sanoq=0;
boolean vazifa1 = true;
boolean vazifa2 = true;
boolean kiruvchi_datchik = false;
boolean chiquvchi_datchik=false;
boolean isPeopleExiting=false;
int i=1;
void setup() {
Serial.begin(9600);
pinMode(birinchi, INPUT);
pinMode(ikkinchi, INPUT);
}
void loop() {  
  if (!digitalRead(birinchi) && i==1 && vazifa1){
     chiquvchi_datchik=true;
     delay(100);
     i++;
     vazifa1 = false;
  }
   else if (!digitalRead(ikkinchi) && i==2 &&   vazifa2){
     Serial.println("Xonaga odam kirdi !!!");
     chiquvchi_datchik=true;
     delay(100);
     i = 1 ;
     sanoq++;
     Serial.print("Xona ichidagi odamlar soni :  ");
     Serial.println(sanoq);
     vazifa2 = false;
  }
   else if (!digitalRead(ikkinchi) && i==1 && vazifa2 ){
     chiquvchi_datchik=true;
     delay(100);
     i = 2 ;
     vazifa2 = false;
  }
  else if (!digitalRead(birinchi) && i==2 && vazifa1 ){
     Serial.println("Xonadan odam chiqib ketti !!!");
     chiquvchi_datchik=true;
     delay(100);
     sanoq--;
       Serial.print("Xona ichidagi odamlar soni :  ");
       Serial.println(sanoq);
     i = 1;
     vazifa1 = false;
  } 
    if (digitalRead(birinchi)){
     vazifa1 = true;
    }
     if (digitalRead(ikkinchi)){
     vazifa2 = true;
    }  
}