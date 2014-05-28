// These are redefined methods for show, strip and begin that are used
// depending on the type of strip we're working with.

#if SINGLE_STRIP

void stripbegin() {
  strip.begin();
}

void show() {
  strip.show();
}

void setPixelColor(uint8_t pixel, uint8_t r, uint8_t g, uint8_t b) {
  strip.setPixelColor(pixel, r, g, b);
}

#else

void stripbegin() {
  for (uint8_t i=0; i< NO_STAVES; i++) {
    strips[i].begin();
  }
}

void show() {
  for (uint8_t i=0; i< NO_STAVES; i++) {
    strips[i].show();
  }
}

void setPixelColor(uint8_t pixel, uint8_t r, uint8_t g, uint8_t b) {
  uint8_t which_strip = pixel / NO_PIXELS_PER_STAVE;
  uint8_t which_pixel = pixel % NO_PIXELS_PER_STAVE;
  
  strips[which_strip].setPixelColor(which_pixel, r, g, b);
}

#endif
