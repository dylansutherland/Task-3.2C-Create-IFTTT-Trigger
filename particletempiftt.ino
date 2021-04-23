// Include library for DHT22 temperature sensor
#include <Adafruit_DHT.h>

// Define which pin on board the sensor is connected to
#define DHTPIN 3 
// Define type of sensor
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

double temp = 0;
    
void setup() 
{
  Serial.begin(9600); 
	dht.begin();
  // Temperature variable accessed by IFTTT
	Particle.variable("temperature", temp);	
}

void loop() 
{
  // Wait one minute
  delay(60000);
  // Read temperature as Celsius
  temp = dht.getTempCelcius();
}
