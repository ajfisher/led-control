/**

Author: Andrew Fisher
Version: 0.1

Notes: Code for sina's fans.

**/


#include <Adafruit_NeoPixel.h>

#define LEDPIN 6

#define NO_STAVES 7
#define NO_PIXELS_PER_STAVE 17
#define NO_LEDS (NO_STAVES * NO_PIXELS_PER_STAVE)

#define FPS 15
#define FPS_MS (1000/FPS)

#define UP 1
#define DOWN -1

#include "definitions.h"

fan thefan;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NO_LEDS, LEDPIN, NEO_GRB + NEO_KHZ800);

uint32_t last_time = 0;
uint32_t next_action_time = 0;


// MAIN BITS HERE

void setup() {
  strip.begin();

  strip.show();
  //stave_build(0, 100, 100, 0, 1, DOWN);
  //stave_build(0, 0, 100, 0, 1, UP);
  //stave_build(1, 0, 100, 0, 1, UP);
  //stave_build(2, 0, 100, 0, 1);
  //stave_build(3, 0, 100, 0, 1);
  //stave_build(4, 0, 100, 0, 1);
  stave_shoot(0, 100, 0, 100, 2, DOWN);
  //pixel_state(0, 0, 100, 100, 100, PIXEL_OFF, 15, PIXEL_ON, 15);
}

void loop() {
  uint16_t cur_time = millis();
  if (cur_time-last_time >= FPS_MS) {
    // we need to update the frame.
    update_leds();
    calculate_next_frame();
    last_time = cur_time;
  }

  if (cur_time >= next_action_time) {
    get_next_action();
  }
  
}




