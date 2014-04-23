// Control for the pixels.

#include <avr/pgmspace.h>

/**sequence sequence_table[] PROGMEM =
{
    {1000, SEQ_STAVE_BUILD_UP, 0, 0, 100, 0, 2},
    {2000, SEQ_STAVE_BUILD_UP, 0, 0, 100, 0, 2},
    {3000, SEQ_STAVE_BUILD_UP, 0, 0, 100, 0, 2},
    {4000, SEQ_STAVE_BUILD_UP, 0, 0, 100, 0, 2},
};**/

uint32_t sequence_table[][7] PROGMEM =
{
    {3000, SEQ_FAN_BUILD_UP, 0, 50, 50, 50, 1},
    {5000, SEQ_FAN_OFF, 0, 0, 0, 0, 1},
    {10000, SEQ_STAVE_BUILD_UP, 0, 0, 20, 0, 1},
    {10500, SEQ_STAVE_BUILD_UP, 1, 0, 40, 0, 1},
    {11000, SEQ_STAVE_BUILD_UP, 2, 0, 60, 0, 1},
    {11500, SEQ_STAVE_BUILD_UP, 3, 0, 80, 0, 1},
    {12000, SEQ_STAVE_BUILD_UP, 4, 0, 100, 0, 1},
    {12500, SEQ_STAVE_BUILD_UP, 5, 0, 120, 0, 1},
    {13000, SEQ_STAVE_BUILD_UP, 6, 0, 140, 0, 1},
};


