// Control for the pixels.

#include <avr/pgmspace.h>

uint32_t sequence_table[][7] PROGMEM =
{

    {10000, SEQ_STAVE_BUILD_UP, 0, 0, 20, 0, 1},
    {10500, SEQ_STAVE_BUILD_UP, 1, 0, 40, 0, 1},
    {11000, SEQ_STAVE_BUILD_UP, 2, 0, 60, 0, 1},
    {11500, SEQ_STAVE_BUILD_UP, 3, 0, 80, 0, 1},
    {12000, SEQ_STAVE_BUILD_UP, 4, 0, 100, 0, 1},
    {12500, SEQ_STAVE_BUILD_UP, 5, 0, 120, 0, 1},
    {13000, SEQ_STAVE_BUILD_UP, 6, 0, 140, 0, 1},
    // now unbild it
    {14000, SEQ_STAVE_UNBUILD, 0, 0, 20, 0, 1},
    {14500, SEQ_STAVE_UNBUILD, 1, 0, 40, 0, 1},
    {15000, SEQ_STAVE_UNBUILD, 2, 0, 60, 0, 1},
    {15500, SEQ_STAVE_UNBUILD, 3, 0, 80, 0, 1},
    {16000, SEQ_STAVE_UNBUILD, 4, 0, 100, 0, 1},
    {16500, SEQ_STAVE_UNBUILD, 5, 0, 120, 0, 1},
    {17000, SEQ_STAVE_UNBUILD, 6, 0, 140, 0, 1},
    // do a full fan build
    {20000, SEQ_FAN_BUILD_UP, 0, 100, 100, 0, 5},
    {27000, SEQ_FAN_UNBUILD, 0, 100, 100, 0, 1},   
};


