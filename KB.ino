// USB HID keyboard emulation test
// target: Pro Micro 5V/16MHz

#include <Keyboard.h> // Arduino keyboard emulation library

const int LED=17; // on-board RX LED, active low
const int buttonR = 3; // input pin for right button
int previousR = LOW; // keep last state of the button
int i=0xc0;
void setup() {
 pinMode(LED, OUTPUT);
 pinMode(buttonR, INPUT_PULLUP);
 Keyboard.begin(); // start HID keyboard emulation
}

void loop() {
 int stateR = digitalRead(buttonR); // poll button state
 if ((stateR != previousR) && (stateR == HIGH)) { // if button state is changed and is high
 Keyboard.write(67); // send 'C' to host
 delay(1000);
 digitalWrite(LED, LOW); delay(10); digitalWrite(LED, HIGH); ;// blink LED once 
 }
 previousR=stateR; // update button state
}
