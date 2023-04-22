/*
  HCSR04 - Arduino library for the HCSR04 ultrasonic distance sensor
  Modified by Segilmez06, 22 April 2023.
  Made by Jørgen Larsen, 30 October 2019.
  Inspired by Martin Sosic, June 11, 2016.
*/

#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include "Arduino.h"

class DistanceSensor {
 public:
    /**
     * @param trigPin  Digital pin for controlling the sensor (output).
     * @param echoPin  Digital pin for receiving data from the sensor (input).
     */
    DistanceSensor(int trigPin, int echoPin);

    /**
     * Measures the distance
     * @returns The distance in cm. For distances longer than 400cm, a negative value is returned.
     */
    double getCM();

    /**
     * Measures the distance
     * @returns The distance in cm. For distances longer than 400cm, a negative value is returned.
     * @param temp  Temperature in degrees Celsius
     */
    double getCM(float temp);
 private:
    int trigPin, echoPin;
};

#endif // DISTANCESENSOR_H
