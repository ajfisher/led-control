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
#include "sequencing.h"



fan thefan;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NO_LEDS, LEDPIN, NEO_GRB + NEO_KHZ800);

uint32_t last_time = 0;
uint32_t next_action_time;
uint16_t no_actions = 0; 
uint8_t current_action_index;
bool actions_finished = false;

uint8_t sequence_size = 0;

uint32_t *current_action;

// MAIN BITS HERE

void setup() {
  strip.begin();
  Serial.begin(9600);
  Serial.println("Debug");
  //Serial.print("Number of items is: ");

  // set up all the action stuff.
  sequence_size = sizeof(sequence_table[0]);
  no_actions = sizeof(sequence_table)/sequence_size;
  //Serial.println(no_actions);
  
  current_action_index = 0;
  next_action_time = sequence_table[0][0]; // set this just to the first one.
  
  strip.show();
}

void loop() {
  
  uint16_t cur_time = millis();
  if (cur_time-last_time >= FPS_MS) {
    // we need to update the frame.
    update_leds();
    calculate_next_frame();
    last_time = cur_time;
  }

  if (cur_time >= next_action_time && !actions_finished) {
    get_next_action();
  }
  
}




