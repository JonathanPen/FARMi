#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25) //SEA LEVEL PRESSURE HPA
// BME280 pins
#define I2C_SDA_2            D2
#define I2C_SCL_2            D1

Adafruit_BME280 bme; // I2C

TwoWire I2CBME = TwoWire();

unsigned long delayTime;

void setup() {
    Serial.begin(9600);
    while(!Serial);    // time to get serial running
    Serial.println(F("BME280 test"));
    
    I2CBME.begin(I2C_SDA_2, I2C_SCL_2, 400000);

    unsigned status;
    
    // default settings
     if (!bme.begin(0x76, &I2CBME))
    {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1)
        ;
    }
    
    Serial.println("-- Default Test --");
    delayTime = 5000;

    Serial.println();
}


void loop() { 
    printValues();
    delay(delayTime);
}


void printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
}
