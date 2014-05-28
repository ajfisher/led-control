#define NO_STAVES 7
#define NO_PIXELS_PER_STAVE 17
#define NO_LEDS (NO_STAVES * NO_PIXELS_PER_STAVE)

// set SINGLESTRIP to true if it's one long strip otherwise to false
// for a set of strips of equal length.
#define SINGLE_STRIP true

#if SINGLE_STRIP
  // PIN number if using a single strip
  #define SINGLE_LED_PIN 3
  
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NO_LEDS, SINGLE_LED_PIN, NEO_GRB + NEO_KHZ800);
#else
  // here you need to define the various pins being used for each stave
  #define SPIN0 2
  #define SPIN1 3
  #define SPIN2 4
  #define SPIN3 5
  #define SPIN4 6
  #define SPIN5 7
  #define SPIN6 8
  
  // now define a strip for each set of neopixels
  Adafruit_NeoPixel strip0 = Adafruit_NeoPixel(NO_PIXELS_PER_STAVE, SPIN0, NEO_GRB + NEO_KHZ800);
  Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NO_PIXELS_PER_STAVE, SPIN1, NEO_GRB + NEO_KHZ800);
  Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NO_PIXELS_PER_STAVE, SPIN2, NEO_GRB + NEO_KHZ800);
  Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NO_PIXELS_PER_STAVE, SPIN3, NEO_GRB + NEO_KHZ800);
  Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(NO_PIXELS_PER_STAVE, SPIN4, NEO_GRB + NEO_KHZ800);
  Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(NO_PIXELS_PER_STAVE, SPIN5, NEO_GRB + NEO_KHZ800);
  Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(NO_PIXELS_PER_STAVE, SPIN6, NEO_GRB + NEO_KHZ800);
  
  // now set up the pin array for later
  int led_strip_pins[] = { SPIN0, SPIN1, SPIN2, SPIN3, SPIN4, SPIN5, SPIN6 };
  
  // and now we need the array of strips to work with too.
  Adafruit_NeoPixel strips[] = {strip0, strip1, strip2, strip3, strip4, strip5, strip6 };

#endif
