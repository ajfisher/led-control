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
    {5000, SEQ_STAVE_SHOOT_UP, 0, 0, 100, 0, 1},
    {7000, SEQ_STAVE_SHOOT_UP, 0, 100, 0, 0, 1},
    {10000, SEQ_STAVE_BUILD_UP, 0, 0, 100, 0, 1},
    {13000, SEQ_STAVE_OFF, 0, 0, 0, 0, 1},
};


