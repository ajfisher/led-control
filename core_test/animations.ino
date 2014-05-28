// Holds all of the different animation forms.

void pixel_state(uint8_t stave_no, uint8_t pixel, uint8_t r, uint8_t g, uint8_t b, \
                PIXEL_STATUS current, uint8_t c_frames, PIXEL_STATUS next, uint8_t n_frames) {
  // sets the status of the pixel
  thefan.staves[stave_no].pixels[pixel].r = r;
  thefan.staves[stave_no].pixels[pixel].g = g;
  thefan.staves[stave_no].pixels[pixel].b = b;
  thefan.staves[stave_no].pixels[pixel].current_status = current;
  thefan.staves[stave_no].pixels[pixel].current_frames = c_frames;
  thefan.staves[stave_no].pixels[pixel].next_status = next;
  thefan.staves[stave_no].pixels[pixel].next_frames = n_frames;
  thefan.staves[stave_no].pixels[pixel].interpolate_position = 0; // set this to starting point in all cases when we set a state
}

void pixel_on(uint8_t stave_no, uint8_t pixel, uint8_t r, uint8_t g, uint8_t b, uint8_t frames) {
  // turns a particular pixel on
  pixel_state(stave_no, pixel, r, g, b, PIXEL_ON, frames, PIXEL_NONE, 0);
}

void pixel_off(uint8_t stave_no, uint8_t pixel, uint8_t frames) {
  // turns a particular pixel off
  pixel_state(stave_no, pixel, 0, 0, 0, PIXEL_OFF, frames, PIXEL_NONE, 0);
}

void pixel_fade_on(uint8_t stave_no, uint8_t pixel, uint8_t r, uint8_t g, uint8_t b, uint8_t frames) {
  // turns a particular pixel off
  pixel_state(stave_no, pixel, r, g, b, PIXEL_FADE_ON, frames, PIXEL_NONE, 0);
}

void pixel_fade_off(uint8_t stave_no, uint8_t pixel, uint8_t r, uint8_t g, uint8_t b, uint8_t frames) {
  // turns a particular pixel off
  pixel_state(stave_no, pixel, r, g, b, PIXEL_FADE_OFF, frames, PIXEL_NONE, 0);
}

void stave_on(uint8_t stave_no, uint8_t r, uint8_t g, uint8_t b) {
  // turn a given stave on.
  for (uint8_t j = 0; j < NO_PIXELS_PER_STAVE; j++) {
      pixel_on(stave_no, j, r, g, b, 1);
  }
}

void stave_off(uint8_t stave_no) {
  // turn a given stave off.
  for (uint8_t j = 0; j < NO_PIXELS_PER_STAVE; j++) {
      pixel_off(stave_no, j, 10);
  }
}

void stave_fade_on(uint8_t stave_no, uint8_t r, uint8_t g, uint8_t b, uint8_t frames) {
  // fades a stave on.
  for (uint8_t j = 0; j < NO_PIXELS_PER_STAVE; j++) {
      pixel_fade_on(stave_no, j, r, g, b, frames);
  }  
}

void stave_fade_off(uint8_t stave_no, uint8_t r, uint8_t g, uint8_t b, uint8_t frames) {
  // fades a stave on.
  for (uint8_t j = 0; j < NO_PIXELS_PER_STAVE; j++) {
      pixel_fade_off(stave_no, j, r, g, b, frames);
  }  
}

void stave_build(uint8_t stave_no, uint8_t r, uint8_t g, uint8_t b, uint8_t frames, int dir) {
  // builds a stave up from fully dark to fully light, one pixel at a time per frame rate in the direction supplied
  if (dir == UP) {
    for (int i=0; i < NO_PIXELS_PER_STAVE; i++) {
      pixel_state(stave_no, i, r, g, b, PIXEL_OFF, i*frames+1, PIXEL_ON, 0); // +1 here is to just eliminate 0 px boundary condition
    }
  } else {
    for (int i=NO_PIXELS_PER_STAVE-1; i >= 0; i--) {
      pixel_state(stave_no, i, r, g, b, PIXEL_OFF, (NO_PIXELS_PER_STAVE-i)*frames+1, PIXEL_ON, 0); // +1 here is to just eliminate 0 px boundary condition
    }
  }
}

void stave_unbuild(uint8_t stave_no, uint8_t r, uint8_t g, uint8_t b, uint8_t frames, int dir) {
  // unbuilds the stave from fully lit to fully dark, switching the pixels off one at a time in the direction supplied
  if (dir == DOWN) {
    for (int i=NO_PIXELS_PER_STAVE-1; i >= 0; i--) {
      pixel_state(stave_no, i, r, g, b, PIXEL_ON, (NO_PIXELS_PER_STAVE-i)*frames+1, PIXEL_OFF, 0); // +1 here is to just eliminate 0 px boundary condition
    }    
  } else {
    for (int i=NO_PIXELS_PER_STAVE-1; i >= 0; i--) {
      pixel_state(stave_no, i, r, g, b, PIXEL_ON, i*frames+1, PIXEL_OFF, 0); // +1 here is to just eliminate 0 px boundary condition
    }
  }
}

void stave_shoot(uint8_t stave_no, uint8_t r, uint8_t g, uint8_t b, uint8_t frames, int dir) {
  // "shoots" a pixel along the course of a stave.
  if (dir == UP) {
    for (int i=0; i < NO_PIXELS_PER_STAVE; i++) {
      pixel_state(stave_no, i, r, g, b, PIXEL_OFF, i*frames+1, PIXEL_ON, frames); 
    }
  } else {
    for (int i=NO_PIXELS_PER_STAVE-1; i >= 0; i--) {
      pixel_state(stave_no, i, r, g, b, PIXEL_OFF, (NO_PIXELS_PER_STAVE-i)*frames+1, PIXEL_ON, frames); 
    }    
  }
}

void stave_streak(uint8_t stave_no, uint8_t r, uint8_t g, uint8_t b, uint8_t frames, int dir) {
  // "shoots" a pixel along the course of a stave.
  if (dir == UP) {
    for (int i=0; i < NO_PIXELS_PER_STAVE; i++) {
      pixel_state(stave_no, i, r, g, b, PIXEL_OFF, i*frames+1, PIXEL_FADE_OFF, frames*NO_PIXELS_PER_STAVE); 
    }
  } else {
    for (int i=NO_PIXELS_PER_STAVE-1; i >= 0; i--) {
      pixel_state(stave_no, i, r, g, b, PIXEL_OFF, (NO_PIXELS_PER_STAVE-i)*frames+1, PIXEL_FADE_OFF, frames*NO_PIXELS_PER_STAVE); 
    }    
  }
}

void fan_build(uint8_t r, uint8_t g, uint8_t b, uint8_t frames, int dir) {
  // builds a fan up from bottom to top with <frames> as the number of frames between each pixel
  for (int stave_no = 0; stave_no < NO_STAVES; stave_no++) {
    stave_build(stave_no, r, g, b, frames, dir);
  }
}

void fan_unbuild(uint8_t r, uint8_t g, uint8_t b, uint8_t frames, int dir) { //TODO
  // unbuilds a fan up from bottom to top assuming fully lit
  for (int stave_no = 0; stave_no < NO_STAVES; stave_no++) {
    stave_unbuild(stave_no, r, g, b, frames, dir);
  }
}

void fan_shoot(uint8_t r, uint8_t g, uint8_t b, uint8_t frames, int dir) {
  // shoots a fan up from bottom to top with <frames> as the number of frames between each pixel
  for (int stave_no = 0; stave_no < NO_STAVES; stave_no++) {
    stave_shoot(stave_no, r, g, b, frames, dir);
  }
}

void fan_streak(uint8_t r, uint8_t g, uint8_t b, uint8_t frames, int dir) {
  // shoots a fan up from bottom to top with <frames> as the number of frames between each pixel with a fade away
  for (int stave_no = 0; stave_no < NO_STAVES; stave_no++) {
    stave_streak(stave_no, r, g, b, frames, dir);
  }
}

void fan_on(uint8_t r, uint8_t g, uint8_t b) {
  // turn a given stave on.
  for (uint8_t j = 0; j < NO_STAVES; j++) {
      stave_on(j, r, g, b);
  }
}

void fan_off() {
  // turn a given stave on.
  for (uint8_t j = 0; j < NO_STAVES; j++) {
      stave_off(j);
  }
}

void fan_fade_on(uint8_t r, uint8_t g, uint8_t b, uint8_t frames) {
  // fades the fan on over the number of frames
  for (int stave_no = 0; stave_no < NO_STAVES; stave_no++) {
    stave_fade_on(stave_no, r, g, b, frames);
  }
}

void fan_fade_off(uint8_t r, uint8_t g, uint8_t b, uint8_t frames) {
  // fades the fan off over the number of frames
  for (int stave_no = 0; stave_no < NO_STAVES; stave_no++) {
    stave_fade_off(stave_no, r, g, b, frames);
  }
}
