#include <Adafruit_NeoPixel.h>
#define BLYNK_PRINT Serial
//#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "StudentNet";
char pass[] = "4153334021";

#define ESP8266_BAUD 115200
ESP8266 wifi(&Serial);

#define PIN 6
#define PIXEL_COUNT 12

unsigned int dimmer = 254;
unsigned int red = 254;
unsigned int green = 254;
unsigned int blue = 254;


Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIN, NEO_GRB + NEO_KHZ800);  //use me
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIN, NEO_GRBW + NEO_KHZ800);  //temp light

void setup()
{
  // Debug console
  Serial.begin(ESP8266_BAUD);
  delay(10);

Blynk.begin(auth, wifi, ssid, pass);

  strip.begin();
  strip.show();

  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, 255, 180, 0);  //default color
    strip.show();
    delay (100);
  }
}
void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V5)
{
  dimmer = param.asInt();

  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, (dimmer * red) / 255, (dimmer * green) / 255, (dimmer * blue) / 255);
  }
  strip.show();
}

BLYNK_WRITE(V6)
{
  red = param[0].asInt();
  green = param[1].asInt();
  blue = param[2].asInt();

  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, (dimmer * red) / 255, (dimmer * green) / 255, (dimmer * blue) / 255);
  }
  strip.show();
}
