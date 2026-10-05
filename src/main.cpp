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
    int potValue = analogRead(POT_PIN);
    unsigned long highTimeUs = map(potValue, 0, 4095, 0, PWM_PERIOD_US);
    
    unsigned long currentMicros = micros();
    unsigned long currentPhase = currentMicros % PWM_PERIOD_US;
    
    if (currentPhase < highTimeUs) {
        digitalWrite(MOTOR_PIN, HIGH);
    } else {
        digitalWrite(MOTOR_PIN, LOW);
    }
}