

#include <RH_ASK.h>
#include <SPI.h> 

RH_ASK driver;

void setup()
{
    Serial.begin(15200);  
    if (!driver.init())
         Serial.println("First attempt in learning");
}

void loop()
{
    uint8_t buf[32];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) 
    {
      int i;
      Serial.print("output: ");
      Serial.println((char*)buf);         
    }
}
