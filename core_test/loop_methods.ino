
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
  // gets the next action that should be undertaken.
  
  Serial.println(F("\ngetting the next action"));
  Serial.print(F("current action: "));
  Serial.println(current_action_index);
 
  Serial.println(F("reading words: "));
  
  // set the vals;
  uint32_t seq_time = pgm_read_word(&(sequence_table[current_action_index][0]));
  SEQUENCES seq = (SEQUENCES)pgm_read_word(&(sequence_table[current_action_index][1]));
  uint8_t item = (uint8_t)pgm_read_word(&(sequence_table[current_action_index][2]));
  uint8_t r = (uint8_t)pgm_read_word(&(sequence_table[current_action_index][3]));
  uint8_t g = (uint8_t)pgm_read_word(&(sequence_table[current_action_index][4]));
  uint8_t b = (uint8_t)pgm_read_word(&(sequence_table[current_action_index][5]));
  uint8_t frames = (uint8_t)pgm_read_word(&(sequence_table[current_action_index][6]));

  Serial.print(F(" seq: "));
  Serial.println(seq);

      //stave_on(item, r, g, b);
  // now we test the types and set the action based upon it.
  switch (seq) {
    case SEQ_STAVE_OFF:
      stave_off(item);
      break;
    case SEQ_STAVE_ON:
      stave_on(item, r, g, b);
      break;
    case SEQ_STAVE_BUILD_UP:
      stave_build(item, r, g, b, frames, UP);
      break;
    case SEQ_STAVE_BUILD_DOWN:
      stave_build(item, r, g, b, frames, DOWN);
      break;
    case SEQ_STAVE_UNBUILD:
      ;
      break;
    case SEQ_STAVE_SHOOT_UP:
      stave_shoot(item, r, g, b, frames, UP);
      break;
    case SEQ_STAVE_SHOOT_DOWN:
      stave_shoot(item, r, g, b, frames, DOWN);
      break;
  }


  // move to the next action but also check we're in bounds. If so we can update the timer
  // if not we say we're finished.
  current_action_index++;
  if (current_action_index >= no_actions) {
    actions_finished = true;
  } else {
    next_action_time = pgm_read_word(&(sequence_table[current_action_index][0]));
  }
  
  Serial.print(F("Vals: "));
  Serial.print(F("ST: "));
  Serial.print(seq_time);
  Serial.print(F(" seq: "));
  Serial.print(seq);
  Serial.print(F(" item: "));
  Serial.print(item);
  Serial.print(F(" r: "));
  Serial.print(r);
  Serial.print(F(" g: "));
  Serial.print(g);
  Serial.print(F(" b: "));
  Serial.print(b);
  Serial.print(F(" f: "));
  Serial.print(frames);
  Serial.println("");
  Serial.print(F("Next action will be at: "));
  Serial.println(next_action_time);
  
}
