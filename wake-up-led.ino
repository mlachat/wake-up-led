#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>

int ledPinRed   = 12;
int ledPinGreen = 8;
int ledPinBlue = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
}

void loop() {
  tmElements_t tm;
  Serial.println("in loop");
  if (RTC.read(tm)) {
    Serial.println("Uhrzeit gelesen");
    if (tm.Hour > 18 && tm.Hour <= 23) {
       Serial.println("es ist zwischen 19 und 24 Uhr");
       digitalWrite(ledPinRed, HIGH);
       digitalWrite(ledPinGreen, LOW);
       digitalWrite(ledPinBlue, LOW);       
    }
    if (tm.Hour >= 0 && tm.Hour <= 5) {
      Serial.println("es ist zwischen 0 und 6 Uhr");
      digitalWrite(ledPinRed, HIGH);
      digitalWrite(ledPinGreen, LOW);
      digitalWrite(ledPinBlue, LOW);
    }
    if (tm.Hour == 6) {
      Serial.println("es ist zwischen 6 und 7 Uhr");
      digitalWrite(ledPinRed, LOW);
      digitalWrite(ledPinGreen, LOW);
      digitalWrite(ledPinBlue, HIGH);
    }
    if (tm.Hour > 6 && tm.Hour <= 17) {
      Serial.println("es ist zwischen 7 und 18 Uhr");
      digitalWrite(ledPinGreen, HIGH);
      digitalWrite(ledPinRed, LOW);
      digitalWrite(ledPinBlue, LOW);
    }
   if (tm.Hour == 18) {
      Serial.println("es ist zwischen 18 und 19 Uhr");
      digitalWrite(ledPinRed, LOW);
      digitalWrite(ledPinGreen, LOW);
      digitalWrite(ledPinBlue, HIGH);
    }
  }
  delay(10000);
}




