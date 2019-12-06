//add on pushbutton allows lamp to have 5 functions
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define PIXEL_COUNT 12
#define BUTTON_PIN 2

unsigned int red = 254;
unsigned int green = 254;
unsigned int blue = 254;

int buttonPress = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIN, NEO_GRB + NEO_KHZ800);  //use me

void setup() {
  //start serial connection
  Serial.begin(9600);
  strip.begin();
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
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, 255, 255, 255); //white
    strip.show();

  }
  delay(2);
}

void cyan() {
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, 0, 255, 255); //cyan
    strip.show();
  }
  delay(2);
}

void magenta() {
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, 255, 0, 255); //magenta
    strip.show();
  }
  delay(2);
}

void yellow() {
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, 255, 255, 0); //yellow
    strip.show();
  }
  delay(2);
}

void blinking() {
  for (int i = 0; i < strip.numPixels(); i++)   //show the color last saved in EEPROM
  {
    strip.setPixelColor(i, 255, 255, 255); //default color
    strip.show();
    delay(100);
    int sensorVal = digitalRead(BUTTON_PIN);   //test for press during sequence
    if (sensorVal == LOW) loop();
    strip.setPixelColor(i, 0, 0, 0); //off
    strip.show();
  }
  delay(2);
}
