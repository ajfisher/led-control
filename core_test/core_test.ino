/**

Author: Andrew Fisher
Version: 0.1

Notes: Code for sina's fans.

**/


#include <Adafruit_NeoPixel.h>

#define LEDPIN 6

#define NO_STAVES 10
#define NO_PIXELS_PER_STAVE 17
#define NO_LEDS (NO_STAVES * NO_PIXELS_PER_STAVE)

#define FPS 10
#define FPS_MS (1000/FPS)

typedef enum PIXEL_STATUS {
  PIXEL_OFF,
  PIXEL_ON,
  PIXEL_FADE_OFF,
  PIXEL_FADE_ON,
  TWINKLE
} ;

typedef enum STAVE_STATUS {
  STAVE_OFF,
  STAVE_ON,
  BUILD,
  SHOOT,
  STAVE_FADE_OFF
} ;

typedef struct {
  uint32_t colour;
  PIXEL_STATUS current_status;
  uint8_t current_frames;
  PIXEL_STATUS next_status;
  uint8_t next_frames;
  
} fan_pixel;

typedef struct {
  fan_pixel pixels[NO_PIXELS_PER_STAVE];
  STAVE_STATUS current_status;
  STAVE_STATUS next_status;
  
} fan_stave;

typedef struct {
  fan_stave staves[NO_STAVES];
  int status;
} fan;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NO_LEDS, LEDPIN, NEO_GRB + NEO_KHZ800);

fan thefan;

uint32_t last_time = 0;
uint32_t next_action_time = 0;

void setup() {
  strip.begin();
}

void loop() {
  uint16_t cur_time = millis();
  if (cur_time-last_time >= FPS_MS) {
    // we need to update the frame.
    update_leds();
    calculate_next_frame();
  }

  if (cur_time >= next_action_time) {
    get_next_action();
  }
  
}


void update_leds() {
// does the update of the LEDs
  strip.show();
}

void calculate_next_frame() {
// calculates the requirments of the next frame 
  for (uint8_t i = 0; i<NO_LEDS; i++) {
    
  }
  
}

void get_next_action() {
  ;
}


