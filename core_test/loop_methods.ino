
// Holds the various methods that are used to do the loop tasks.

void update_leds() {
  // does the update of the LEDs
  show();
}

void calculate_next_frame() {
  // calculates the requirments of the next frame 

    uint8_t cur_pixel = 0;
  for (uint8_t i = 0; i<NO_STAVES; i++) {
    for (uint8_t j = 0; j < NO_PIXELS_PER_STAVE; j++) {

      float inter_amt;
      // do calcs here to work out what the next frame should be.
      switch (thefan.staves[i].pixels[j].current_status){
      case PIXEL_OFF:
        setPixelColor(cur_pixel, 0, 0, 0);
        break;
      case PIXEL_ON:
        setPixelColor(cur_pixel, thefan.staves[i].pixels[j].r, thefan.staves[i].pixels[j].g, thefan.staves[i].pixels[j].b);
        break;
      case PIXEL_FADE_ON:
        // does the next step in the fade.
        // Advance the interpolate position by the amount of one frame
        thefan.staves[i].pixels[j].interpolate_position += (255 - thefan.staves[i].pixels[j].interpolate_position) / thefan.staves[i].pixels[j].current_frames;          
        if (thefan.staves[i].pixels[j].interpolate_position > 255) thefan.staves[i].pixels[j].interpolate_position = 255;

        inter_amt = (float)thefan.staves[i].pixels[j].interpolate_position / 255; // gives us a percentage

        setPixelColor(cur_pixel, thefan.staves[i].pixels[j].r*inter_amt, thefan.staves[i].pixels[j].g*inter_amt, thefan.staves[i].pixels[j].b*inter_amt);
        break;
      case PIXEL_FADE_OFF:
        // does the next step in the fade
        // advance the interpolation position by the amount required for one frame
        thefan.staves[i].pixels[j].interpolate_position += (255 - thefan.staves[i].pixels[j].interpolate_position) / thefan.staves[i].pixels[j].current_frames;          
        if (thefan.staves[i].pixels[j].interpolate_position > 255) thefan.staves[i].pixels[j].interpolate_position = 255;

        inter_amt = 1-((float)thefan.staves[i].pixels[j].interpolate_position / 255); // gives us a percentage decreasing

        setPixelColor(cur_pixel, thefan.staves[i].pixels[j].r*inter_amt, thefan.staves[i].pixels[j].g*inter_amt, thefan.staves[i].pixels[j].b*inter_amt);
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
        } 
        else {
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

  // set the vals;
  uint32_t seq_time = pgm_read_dword(&(sequence_table[current_action_index][0]));
  SEQUENCES seq = (SEQUENCES)pgm_read_word(&(sequence_table[current_action_index][1]));
  uint8_t item = (uint8_t)pgm_read_word(&(sequence_table[current_action_index][2]));
  uint8_t r = (uint8_t)pgm_read_word(&(sequence_table[current_action_index][3]));
  uint8_t g = (uint8_t)pgm_read_word(&(sequence_table[current_action_index][4]));
  uint8_t b = (uint8_t)pgm_read_word(&(sequence_table[current_action_index][5]));
  uint8_t frames = (uint8_t)pgm_read_word(&(sequence_table[current_action_index][6]));

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
    // deprecated
    stave_unbuild(item, r, g, b, frames, UP);
    break;
  case SEQ_STAVE_UNBUILD_UP:
    stave_unbuild(item, r, g, b, frames, UP);
    break;
  case SEQ_STAVE_UNBUILD_DOWN:
    stave_unbuild(item, r, g, b, frames, DOWN);
    break;
  case SEQ_STAVE_SHOOT_UP:
    stave_shoot(item, r, g, b, frames, UP);
    break;
  case SEQ_STAVE_SHOOT_DOWN:
    stave_shoot(item, r, g, b, frames, DOWN);
    break;
  case SEQ_STAVE_FADE_ON:
    stave_fade_on(item, r, g, b, frames);
    break;
  case SEQ_STAVE_FADE_OFF:
    stave_fade_off(item, r, g, b, frames);
    break;
  case SEQ_STAVE_STREAK_UP:
    stave_streak(item, r, g, b, frames, UP);
    break;
  case SEQ_STAVE_STREAK_DOWN:
    stave_streak(item, r, g, b, frames, DOWN);
    break;
  case SEQ_FAN_BUILD_UP:
    fan_build(r, g, b, frames, UP);
    break;
  case SEQ_FAN_BUILD_DOWN:
    fan_build(r, g, b, frames, DOWN);
    break;
  case SEQ_FAN_UNBUILD_UP:
    fan_unbuild(r, g, b, frames, UP);
    break;
  case SEQ_FAN_UNBUILD_DOWN:
    fan_unbuild(r, g, b, frames, DOWN);
    break;
  case SEQ_FAN_SHOOT_UP:
    fan_shoot(r, g, b, frames, UP);
    break;
  case SEQ_FAN_SHOOT_DOWN:
    fan_shoot(r, g, b, frames, DOWN);
    break;
  case SEQ_FAN_STREAK_UP:
    fan_streak(r, g, b, frames, UP);
    break;
  case SEQ_FAN_STREAK_DOWN:
    fan_streak(r, g, b, frames, DOWN);
    break;
  case SEQ_FAN_OFF:
    fan_off();
    break;
  case SEQ_FAN_ON:
    fan_on(r, g, b);
  case SEQ_FAN_FADE_ON:
    fan_fade_on(r, g, b, frames);
    break;
  case SEQ_FAN_FADE_OFF:
    fan_fade_off(r, g, b, frames);
    break;
  }


  // move to the next action but also check we're in bounds. If so we can update the timer
  // if not we say we're finished.
  current_action_index++;
  if (current_action_index >= no_actions) {
    actions_finished = true;
  } 
  else {
    next_action_time = pgm_read_dword(&(sequence_table[current_action_index][0]));
  }

}


