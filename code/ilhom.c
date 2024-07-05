// Bu Arduino Uno dan foydalanib 8 ta kanalli savol-javob buzzeri uchun kod.


int buzzerPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // har bir o'yinchi uchun buzzer pinlari
int buttonPins[] = {10, 11, 12, 13, A0, A1, A2, A3}; // har bir o'yinchi uchun tugma pinlari
int ledPins[] = {22, 23, 24, 25, 26, 27, 28, 29}; // har bir o'yinchi uchun LED pinlari
int delayTime = 1000; // buzzer ovozini kutingan vaqt

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(buzzerPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { // agar o'yinchi tugmasini bossa
      digitalWrite(ledPins[i], HIGH); // o'yinchining LEDni yonib qo'ying
      digitalWrite(buzzerPins[i], HIGH); // o'yinchi buzzerini yonib qo'ying
      delay(delayTime); // buzzer ovozini kutingan vaqt
      digitalWrite(buzzerPins[i], LOW); // o'yinchi buzzerini o'chiring
      digitalWrite(ledPins[i], LOW); // o'yinchining LEDni o'chiring
      while (digitalRead(buttonPins[i]) == LOW) {} // o'yinchining tugmasini qo'lga tushirishini kutib oling
    }
  }
}

/*
Bu kodda, har bir o'yinchi uchun buzzer pinlari, tugma pinlari va LED pinlari uchun massivlar aniqlaymiz. 
Biz tugma uchun kirish pinlarini pull-up sifatida sozlaymiz, shuningdek, tugma bosilganda uning qiymati LOW bo'ladi.
Setup funksiyasida, biz pinlarni kirish yoki chiquvchi pinlar sifatida aniqlaymiz.
Loop funksiyasida, biz har bir o'yinchi tugma pinidan o'tamiz. 
Agar o'yinchi tugmasini bosib qo'ygan bo'lsa, biz uning LED va buzzerini yoqamiz, kutingan vaqt kutamiz, keyin ularni o'chiramiz. 
Biz ham o'sha o'yinchining tugmasini qo'lga tushirguncha kutingiz. Keyingi o'yinchi tugmasini tekshirishdan oldin kodni o'zgartirish mumkin, yoki buzzer ovozining turini o'zgartirish mumkin.
*/