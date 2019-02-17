#include <Adafruit_NeoPixel.h>

#include <String.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


#define PIN 6

#define NUMPIXELS      50

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB);

int delayval = 300; // delay for half a second

void setup() {
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  Serial.begin(9600); //might not be this bitrate
  pixels.begin(); // This initializes the NeoPixel library.
}

String input = "HALLOWEEN";

uint32_t Red = pixels.Color(150, 0, 0);
uint32_t Orange = pixels.Color(255, 127, 0);
uint32_t Yellow = pixels.Color(255, 255, 0);
uint32_t Green = pixels.Color(0, 255, 0);
uint32_t Blue = pixels.Color(0, 0, 255);
uint32_t Indigo = pixels.Color(75, 0, 130);
uint32_t Violet = pixels.Color(148, 0, 211);

uint32_t Off = pixels.Color(0, 0, 0);
uint32_t COOLER = Off;

void strangerThings(String inString) {
  inString.toUpperCase();
  for (int i = 0; i < inString.length(); i++) {
    int chari = inString.charAt(i);
    chari = chari  - '@';
    int colorPos = chari % 3;
    if (colorPos == 1) {
      COOLER = Blue;
    }
    else if (colorPos == 2) {
      COOLER = Red;
    }

    else {
      COOLER = Green;
    }
    pixels.setPixelColor(chari - 1, COOLER);
    pixels.show();
    delay(2 * delayval); // Delay for a period of time (in milliseconds)
    pixels.setPixelColor(chari - 1, Off);
    pixels.show();
    delay(delayval);
  }
}

void rainbow() {

  for (int i = -6 ; i < (NUMPIXELS + 6); i++) {
    pixels.setPixelColor(i + 6, Red);
    pixels.setPixelColor(i + 5, Orange);
    pixels.setPixelColor(i + 4, Yellow);
    pixels.setPixelColor(i + 3, Green);
    pixels.setPixelColor(i + 2, Blue);
    pixels.setPixelColor(i + 1, Indigo);
    pixels.setPixelColor(i, Violet);
    pixels.setPixelColor(i - 1, Off);
    pixels.show();
    delay(delayval / 4);
    /*for (int i=0;i<NUMBPIXELS; i++){

      }*/
  }
}

void clearAll() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, Off);
    pixels.show();
  }
}

void loop() {
  clearAll();
  if (Serial.available() > 0){
    String a = Serial.readString();
    strangerThings(a);
    //rainbow();
  }
  //rainbow();
  delay(1 * delayval);
}
