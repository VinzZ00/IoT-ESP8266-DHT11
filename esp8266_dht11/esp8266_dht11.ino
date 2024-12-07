#include "DHTesp.h"

#define DHTpin 5   // D1 of NodeMCU is GPIO5

DHTesp dht;

void setup()
{
  Serial.begin(9600); //Starting serial Communication seperti yang di minta di baudrate 9600
  Serial.println("Starting setup for DHT"); 
  dht.setup(DHTpin, DHTesp::DHT11); //for DHT11 Connect DHT sensor to GPIO5
  
  // Optionally print the sensor's initial status
  Serial.print("Sensor status: ");
  Serial.println(dht.getStatusString());
}

void loop()
{
  // delay untuk minimum sampling period dari library DHTesp.h 
//   unsigned long DHTesp::getMinimumSamplingPeriod() {
//     if (this->_type == DHT11) return 1000; // 1 second
//     if (this->_type == DHT22) return 2000; // 2 seconds
//     return 0; // Default for unknown types
// }
  delay(dht.getMinimumSamplingPeriod()); 

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  // Pengecekan apakah humidity atau temperature Nan atau tidak
  if (isnan(humidity) || isnan(temperature)) {
    Serial.print("Error: ");
    Serial.println(dht.getStatusString());
  }

  Serial.print("Status: ");
  Serial.print(dht.getStatusString());
  Serial.print("\t||\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\t||\t");
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}