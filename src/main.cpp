#include <Arduino.h>

const int POT_PIN = 4;
const int MOTOR_PIN = 5;

const unsigned long PWM_FREQ_HZ = 500;
const unsigned long PWM_PERIOD_US = 1000000 / PWM_FREQ_HZ;

void setup() {
    Serial.begin(115200);
    
    pinMode(MOTOR_PIN, OUTPUT);
    digitalWrite(MOTOR_PIN, LOW);
    
    analogReadResolution(12);
}

void loop() {
    // Logic will be added here
}