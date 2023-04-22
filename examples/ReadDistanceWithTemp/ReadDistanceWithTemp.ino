/*
    This example combines the room temperature and the distance
    to get more accurate results. Then prints the value to the
    serial port.

    Required libraries:
    Adafruit DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
    Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
*/

#include <DistanceSensor.h>
#include <DHT.h>


// Uncomment the type of sensor in use:
//#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

const int echoPin = 12;
const int trigPin = 13;
const int dhtPin = 2;

// Start the sensors
DistanceSensor sensor(trigPin, echoPin);
DHT dht(dhtPin);

void setup () {
    // Start serial port
    Serial.begin(115200);

    // Start the DHT sensor
    dht.begin();

    // Wait a bit before starting
    delay(1500);
}

void loop () {
    // Get room temperature
    int temperature = dht.readTemperature();

    // Get distance in cm
    int distance = sensor.getCM(temperature);

    // Write values to serial port
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print("cm, Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");

    // Wait a bit
    delay(1500);
}
