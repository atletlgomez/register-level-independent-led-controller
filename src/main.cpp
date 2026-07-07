#include <Arduino.h>

unsigned long currentTime = 0; 

struct Led {

  int led;
  byte mask;
  int ledState;
  unsigned long prevTime = 0;
  unsigned long ledInt = 0; 

  Led(int ledNum, int startState, int interval)
    : led(ledNum), ledState(startState), ledInt(interval), mask(1<< ledNum) {};
};

void ledInterval(Led& light) {

  if (currentTime - light.prevTime >= light.ledInt) {
    light.ledState = !light.ledState;
    light.ledState == HIGH ? PORTD |= light.mask: PORTD &= ~light.mask;
    light.prevTime = currentTime;

  }

}

Led led1(2, LOW, 200);
Led led2(3, LOW, 300);
Led led3(4, LOW, 400);



void setup() {
  Serial.begin(9600);
  DDRD |= (1 << 2) | (1 << 3) | (1 << 4);
}

void loop() {

  currentTime = millis();

  ledInterval(led1);
  Serial.print("LED 1 STATE: ");
  Serial.println(led1.ledState);

  ledInterval(led2);
  Serial.print("LED 2 STATE: ");
  Serial.println(led2.ledState);

  ledInterval(led3);
  Serial.print("LED 3 STATE: ");
  Serial.println(led3.ledState);

}