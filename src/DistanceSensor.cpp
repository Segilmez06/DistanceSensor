/*
  HCSR04 - Arduino library for the HCSR04 ultrasonic distance sensor
  Modified by Segilmez06, 22 April 2023.
  Made by Jørgen Larsen, 30 October 2019.
  Inspired by Martin Sosic, June 11, 2016.
*/

#include "Arduino.h"
#include "DistanceSensor.h"

DistanceSensor::DistanceSensor (int trigPin, int echoPin) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

double DistanceSensor::getCM() {
    //The distance is measured based on a standard temperature of 19,307 degrees Celsius, which corresponds to approximately 343m/s for sound.
    return getCM(19.307);
}

double DistanceSensor::getCM(float temp) {
    // First make sure trigPin is LOW
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    //To activate the sensor trigPin is held HIGH for 10 microseconds.
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    //The sensor now resets the distance by keeping echoPin HIGH for a period corresponding to the distance measured.
    unsigned long durationMicroSec = pulseIn(echoPin, HIGH);

    double speedOfSoundInCmPerMs = 0.03313 + 0.0000606 * temp; // Approx ≈ (331.3 + 0.606 ⋅ ϑ) m/s
    double distanceCm = durationMicroSec / 2.0 * speedOfSoundInCmPerMs;
    if (distanceCm == 0 || distanceCm > 400) {
        return -1.0 ;
    } else {
        return distanceCm;
    }
}
