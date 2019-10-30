#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
//char ssid[] = "";
//char pass[] = "";
char ssid[] = "StudentNet";
char pass[] = "4153334021";

#define ESP8266_BAUD 115200
ESP8266 wifi(&Serial);

void setup()
{
 // Debug console
 Serial.begin(ESP8266_BAUD);
 delay(10);
 
 Blynk.begin(auth, wifi, ssid, pass);
}
void loop()
{
 Blynk.run();
} 
