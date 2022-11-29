#include <FastLED.h>

#define LED_PIN     10
#define NUM_LEDS    8
#define BRIGHTNESS  20
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100


CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    
    
}

void loop(){
  for(int i = 0; i < 8; i++){
    if(i % 4 == 0){
      leds[i].setRGB(0, 255, 0);
    }
    if(i % 4 == 1){
      leds[i].setRGB(255, 0, 0);
    }
    if(i % 4 == 2){
      leds[i].setRGB(0, 0, 255);
    }
    if(i % 4 == 3){
      leds[i].setRGB(255, 255, 0);
    }
      
  }
  FastLED.show();

  delay(200);
  for(int i = 0; i < 8; i++){
     leds[i].setRGB(0, 0, 0);
  }
  FastLED.show();
  delay(200);
}
