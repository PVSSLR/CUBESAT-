#include <SPI.h>        // Include SPI library (needed for the SD card)
#include <SD.h>         // Include SD library
#include<dht.h>      // Include DHT sensor library
 
File dataFile;
 
          // DHT11 data pin is connected to Arduino pin 4
dht DHT;

#define DHT11_PIN 8
 
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
    ; // wait for serial port to connect. Needed for native USB port only
  Serial.print("Initializing SD card...");
  if (!SD.begin()) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  delay(2000);
}
 
uint16_t line = 1;
 
void loop() {
  delay(1000);
  // Read humidity
 // byte RH = dht.readHumidity();
  //Read temperature in degree Celsius
  //byte Temp = dht.readTemperature();

  byte chk = DHT.read11(DHT11_PIN);
    

  
  dataFile = SD.open("DHT11Log.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (dataFile) {
    Serial.print(line);
    Serial.print(":    Temperature = ");
    Serial.print(DHT.temperature);
    Serial.print("    Humidity = ");
    Serial.println(DHT.humidity);
    // Write data to SD card file (DHT11Log.txt)
    dataFile.print(line++);
    dataFile.print(":    Temperature = ");
    dataFile.print(DHT.temperature);
    dataFile.print("°C,    Humidity = ");
    dataFile.println(DHT.humidity);
    dataFile.close();
    
  }
  // if the file didn't open, print an error:
  else
    Serial.println("error opening DHT11Log.txt");
}
