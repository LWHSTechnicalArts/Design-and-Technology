#define BLYNK_PRINT Serial

#include <Adafruit_NeoPixel.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <EEPROM.h>

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


Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIN, NEO_GRB + NEO_KHZ800);  //light initialization

void setup()
{
  // Debug console
  Serial.begin(ESP8266_BAUD);
  delay(10);

  red = EEPROM.read(0);
  green = EEPROM.read(1);
  blue = EEPROM.read(2);
  dimmer = EEPROM.read(3);

  strip.begin();

  for (int i = 0; i < strip.numPixels(); i++)   //show the color last saved in EEPROM
  {
    strip.setPixelColor(i, (dimmer * red) / 255, (dimmer * green) / 255, (dimmer * blue) / 255); //default color
    strip.show();
    delay (50);
  }
  delay(1000);
  Blynk.begin(auth, wifi, ssid, pass);
}

void loop()
{
  Blynk.run();
}

//-----BLYNK virual pin functions-----V

BLYNK_WRITE(V5)
{
  dimmer = param.asInt();

  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, (dimmer * red) / 255, (dimmer * green) / 255, (dimmer * blue) / 255);
  }
  strip.show();
  EEPROM.write(3, dimmer);   //store dimmer data in EEPROM
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
  
  EEPROM.write(0, red);    //store RGB data in EEPROM
  EEPROM.write(1, green);
  EEPROM.write(2, blue);
}
