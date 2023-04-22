# DistanceSensor

![GitHub Workflow Status (with branch)](https://img.shields.io/github/actions/workflow/status/Segilmez06/DistanceSensor/check-lint.yml?branch=development&color=blue&label=Lint%20Check&logo=Github&logoColor=white&style=flat-square)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/Segilmez06/DistanceSensor?display_name=tag&label=Latest%20Release&color=blue&logo=Github&logoColor=white&style=flat-square)

A simple library for the HC-SR04 ultrasonic distance sensor. It measures the time between the sensor's trigger and echo pins. The library is designed to be used with the Arduino IDE. Compitable with most Arduino and ESP boards.

## Installation

Download the library and place it in your Arduino libraries folder. You can find the location of your libraries folder by going to `File > Preferences` in the Arduino IDE.

## Usage

```c++

#include <DistanceSensor.h>


const int echoPin = 12;
const int trigPin = 13;

// Start the sensor
DistanceSensor sensor(trigPin, echoPin);

void setup () {
    // Start serial port
    Serial.begin(115200);
}

void loop () {
    // Get distance in cm
    int distance = sensor.getCM();

    // Write values to serial port
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("cm");

    // Wait a bit
    delay(500);
}

```

## Credits

Original library from [Afstandssensor](https://github.com/Teknologiskolen/HCSR04) authors.

I just translated it to English and added some examples.
