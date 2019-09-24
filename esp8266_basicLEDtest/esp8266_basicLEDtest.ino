#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "b875f63dc86944fa9b6bc0f404a3e6aa";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ATT8WPP966";
char pass[] = "9a99f38=4w=7";
//char ssid[] = "StudentNet";
//char pass[] = "4153334021";

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
