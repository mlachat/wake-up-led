#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>

int ledPinRed   = 12;
int ledPinGreen = 8;

void setup() {
  Serial.begin(9600);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
}

void loop() {
  tmElements_t tm;
  
  if (RTC.read(tm)) {
    if (tm.Hour > 18 && tm.Hour <= 23) {
      Serial.println("es ist zwischen 19 und 24 Uhr");
       digitalWrite(ledPinRed, HIGH);
       digitalWrite(ledPinGreen, LOW);
    }
    if (tm.Hour >= 0 && tm.Hour <= 5) {
      Serial.println("es ist zwischen 0 und 6 Uhr");
      digitalWrite(ledPinRed, HIGH);
      digitalWrite(ledPinGreen, LOW);
    }
    if (tm.Hour > 5 && tm.Hour <= 18) {
      Serial.println("es ist zwischen 6 und 19 Uhr");
      digitalWrite(ledPinGreen, HIGH);
      digitalWrite(ledPinRed, LOW);
    }
  }
  delay(10000);
}




