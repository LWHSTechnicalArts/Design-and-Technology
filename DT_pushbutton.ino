//add on pushbutton allows lamp to have 5 functions
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 6
#define BUTTON_PIN 2

unsigned int red = 254;
unsigned int green = 254;
unsigned int blue = 254;

int buttonPress = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);  //use me

void setup() {
  //start serial connection
  Serial.begin(9600);
  pixels.begin();
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(BUTTON_PIN);
  //print out the value of the pushbutton
  Serial.println(sensorVal);
  if (sensorVal == LOW) {
    buttonPress++;
    delay(250);
    if (buttonPress > 4) buttonPress = 0;
  }
  switch (buttonPress) {
    case 0:
      white();
      break;
    case 1:
      cyan();
      break;
    case 2:
      magenta();
      break;
    case 3:
      yellow();
      break;
    case 4:
      blinking();
      break;
  }
}

void white() {
  for (int i = 0; i < pixels.numPixels(); i++)
  {
    pixels.setPixelColor(i, 255, 255, 255); //white
    pixels.show();

  }
  delay(5);
}

void cyan() {
  for (int i = 0; i < pixels.numPixels(); i++)
  {
    pixels.setPixelColor(i, 0, 255, 255); //cyan
    pixels.show();
  }
  delay(5);
}

void magenta() {
  for (int i = 0; i < pixels.numPixels(); i++)
  {
    pixels.setPixelColor(i, 255, 0, 255); //magenta
    pixels.show();
  }
  delay(5);
}

void yellow() {
  for (int i = 0; i < pixels.numPixels(); i++)
  {
    pixels.setPixelColor(i, 255, 255, 0); //yellow
    pixels.show();
  }
  delay(5);
}

void blinking() {
  for (int i = 0; i < pixels.numPixels(); i++)   //show the color last saved in EEPROM
  {
    pixels.setPixelColor(i, 255, 255, 255); //default color
    pixels.show();
    delay(100);
    int sensorVal = digitalRead(BUTTON_PIN);   //test for press during sequence
    if (sensorVal == LOW) loop();
    pixels.setPixelColor(i, 0, 0, 0); //off
    pixels.show();
  }
  delay(5);
}
