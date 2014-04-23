// Holds all of the different animation components

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
}

void pixel_on(uint8_t stave_no, uint8_t pixel, uint8_t r, uint8_t g, uint8_t b, uint8_t frames) {
  // turns a particular pixel on
  pixel_state(stave_no, pixel, r, g, b, PIXEL_ON, frames, PIXEL_NONE, 0); 
}

void pixel_off(uint8_t stave_no, uint8_t pixel, uint8_t frames) {
  // turns a particular pixel off
  pixel_state(stave_no, pixel, 0, 0, 0, PIXEL_OFF, frames, PIXEL_NONE, 0);
}

void stave_on(uint8_t stave_no, uint8_t r, uint8_t g, uint8_t b) {
  // turn a given stave on.
  for (uint8_t j = 0; j < NO_PIXELS_PER_STAVE; j++) {
      pixel_on(stave_no, j, r, g, b, 10);
  }
}

void stave_off(uint8_t stave_no) {
  // turn a given stave off.
  for (uint8_t j = 0; j < NO_PIXELS_PER_STAVE; j++) {
      pixel_off(stave_no, j, 10);
  }
}

void stave_build(uint8_t stave_no, uint8_t r, uint8_t g, uint8_t b, uint8_t frames, int dir) {
  // builds a stave up from bottom to top with <frames> as the number of frames between each item
  if (dir == UP) {
    for (int i=0; i < NO_PIXELS_PER_STAVE; i++) {
      pixel_state(stave_no, i, r, g, b, PIXEL_OFF, i*frames+1, PIXEL_ON, 0); // +1 here is to just eliminate 0 px boundary condition
    }
  } else {
    for (int i=NO_PIXELS_PER_STAVE; i >= 0; i--) {
      pixel_state(stave_no, i, r, g, b, PIXEL_OFF, (NO_PIXELS_PER_STAVE-i)*frames+1, PIXEL_ON, 0); // +1 here is to just eliminate 0 px boundary condition
    }
  }
}

void stave_shoot(uint8_t stave_no, uint8_t r, uint8_t g, uint8_t b, uint8_t frames, int dir) {
  // builds a stave up from bottom to top with <frames> as the number of frames between each item
  if (dir == UP) {
    for (int i=0; i < NO_PIXELS_PER_STAVE; i++) {
      pixel_state(stave_no, i, r, g, b, PIXEL_OFF, i*frames+1, PIXEL_ON, frames); 
    }
  } else {
    for (int i=NO_PIXELS_PER_STAVE; i >= 0; i--) {
      pixel_state(stave_no, i, r, g, b, PIXEL_OFF, (NO_PIXELS_PER_STAVE-i)*frames+1, PIXEL_ON, frames); 
    }    
  }
}



/**void pixel_fade_on(uint8_t stave_no, uint8_t pixel, uint8_t r, uint8_t g, uint8_t b, uint8_t frames) {
  // fades a particular pixel on. assumes the pixel is off if we're doing a fade.
    //pixel_state(stave_no, pixel, r, g, b, PIXEL_FADE_ON, frames, PIXEL_ON, 0);
}**/
