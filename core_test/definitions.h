// Holds all of the various definitions for structs etc.

enum SEQUENCES {
  SEQ_STAVE_OFF,
  SEQ_STAVE_ON,
  SEQ_STAVE_BUILD_UP,
  SEQ_STAVE_BUILD_DOWN,
  SEQ_STAVE_UNBUILD,        // deprecated
  SEQ_STAVE_UNBUILD_UP,
  SEQ_STAVE_UNBUILD_DOWN,
  SEQ_STAVE_SHOOT_UP,
  SEQ_STAVE_SHOOT_DOWN,
  SEQ_FAN_BUILD_UP,
  SEQ_FAN_BUILD_DOWN,
  SEQ_FAN_UNBUILD,          // deprecated
  SEQ_FAN_UNBUILD_UP,
  SEQ_FAN_UNBUILD_DOWN,
  SEQ_FAN_SHOOT_UP,
  SEQ_FAN_SHOOT_DOWN,
  SEQ_FAN_ON,
  SEQ_FAN_OFF
};

enum PIXEL_STATUS {
  PIXEL_OFF,
  PIXEL_ON,
  PIXEL_FADE_OFF,
  PIXEL_FADE_ON,
  TWINKLE,
  PIXEL_WAIT,
  PIXEL_NONE
} ;

enum STAVE_STATUS {
  STAVE_OFF,
  STAVE_ON,
  BUILD,
  SHOOT,
  STAVE_FADE_OFF
} ;

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
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
} fan;

typedef struct {
  uint32_t time;
  SEQUENCES seq;
  uint8_t item;
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t frames;
} sequence;

