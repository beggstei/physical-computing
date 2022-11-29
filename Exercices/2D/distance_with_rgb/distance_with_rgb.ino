// NeoPixel test program showing use of the WHITE channel for RGBW
// pixels only (won't look correct on regular RGB NeoPixel strips).
#include <Wire.h>
#include "Adafruit_VL6180X.h"

Adafruit_VL6180X vl = Adafruit_VL6180X();

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN     10

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT  8

// NeoPixel brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 50 // Set BRIGHTNESS to about 1/5 (max = 255)

// Declare our NeoPixel strip object:
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

long int minVal= 1000;
long int maxVal= 0;

int ledsR[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int ledsG[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int ledsB[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  
  pixels.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();            // Turn OFF all pixels ASAP
  pixels.setBrightness(BRIGHTNESS);

  Serial.begin(115200);
  pinMode(10, OUTPUT);
  // wait for serial port to open on native usb devices
  while (!Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL6180x test!");
  if (! vl.begin()) {
    Serial.println("Failed to find sensor");
    while (1);
  }
  Serial.println("Sensor found!");

  
}

void loop() {

  uint8_t range = vl.readRange();
  if(minVal > range){
    minVal = range;
  }
   if(maxVal < range){
    maxVal = range;
  }

  Serial.println(maxVal);
  Serial.println(minVal);
  Serial.println(range);
  
  pixels.clear();
  if(range > 0 && range < 255/8){
    pixels.setPixelColor(7, 255, 0, 255);
  }
  if(range > 0 && range < (255/8)*2){
    pixels.setPixelColor(6, 0, 32, 255);
  }
  if(range > 0 && range < (255/8)*3){
    pixels.setPixelColor(5, 0, 64, 255);
  }
  if(range > 0 && range < (255/8)*4){
    pixels.setPixelColor(4, 0, 96, 255);
  }
  if(range > 0 && range < (255/8)*5){
    pixels.setPixelColor(3, 0, 128, 255);
  }
  if(range > 0 && range < (255/8)*6){
    pixels.setPixelColor(2, 0, 160, 255);
  }
  if(range > 0 && range < (255/8)*7){
    pixels.setPixelColor(1, 0, 192, 255);
  }
  if(range > 0 && range < (255/8)*8){
    pixels.setPixelColor(0, 0, 255, 255);
  }
  
  pixels.show();
}
