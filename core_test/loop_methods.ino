
// Holds the various methods that are used to do the loop tasks.

void update_leds() {
// does the update of the LEDs
  //Serial.println("Doing the show of the strip");
  strip.show();
}

void calculate_next_frame() {
// calculates the requirments of the next frame 

  //Serial.println("calc next frame");
  uint8_t cur_pixel = 0;
  for (uint8_t i = 0; i<NO_STAVES; i++) {
    for (uint8_t j = 0; j < NO_PIXELS_PER_STAVE; j++) {
      
      // do calcs here to work out what the next frame should be.
      switch (thefan.staves[i].pixels[j].current_status){
        case PIXEL_OFF:
          strip.setPixelColor(cur_pixel, 0, 0, 0);
          break;
        case PIXEL_ON:
          strip.setPixelColor(cur_pixel, thefan.staves[i].pixels[j].r, thefan.staves[i].pixels[j].g, thefan.staves[i].pixels[j].b);
          break;    
      }
      
      // check to see if we've hit a state change
      if (--thefan.staves[i].pixels[j].current_frames <= 0) {
        // we've hit one, so change the current status to the next one.
        // hold the current state as we'll need that to flip back to potentially
        PIXEL_STATUS t_stat = thefan.staves[i].pixels[j].current_status;
        if (thefan.staves[i].pixels[j].next_frames > 0) {
          // we have a positive frame for the next sequence which means we need to flip back after it.
          thefan.staves[i].pixels[j].current_status = thefan.staves[i].pixels[j].next_status;
          thefan.staves[i].pixels[j].next_status = t_stat;
          thefan.staves[i].pixels[j].current_frames = thefan.staves[i].pixels[j].next_frames;
          thefan.staves[i].pixels[j].next_frames = 0;
        } else {
          // just flip to the next state and be done.
          thefan.staves[i].pixels[j].current_status = thefan.staves[i].pixels[j].next_status;
        }
      }

      cur_pixel++;
    }
  }
  
}

void get_next_action() {
  ;
}
