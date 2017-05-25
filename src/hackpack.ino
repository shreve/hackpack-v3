#include "application.h"
#include <string.h>
#include <stdint.h>
#include "neopixel.h"
#include "cmd.h"
#include "pixel_grid.h"
#include "states.h"

//*****************************************
//We have some particle specific stuff here
PRODUCT_ID(3920);
PRODUCT_VERSION(8);
SYSTEM_MODE(SEMI_AUTOMATIC);

//*********************************************************************************
// Put your custom lighting sequence here, it can be an animation or a static image
// Display it by texting 'animate custom' to your device
// Color Format is 24-bit RGB (written in hex)
//*********************************************************************************

uint32_t red    = 0xFF0000;
uint32_t orange = 0xFF9500;
uint32_t yellow = 0xFFFF00;
uint32_t green  = 0x00FF00;
uint32_t blue   = 0x00FFFF;
uint32_t indigo = 0x0000FF;
uint32_t violet = 0xFF00FF;

uint32_t custom_animation_lut[][16] = {
  { violet, indigo, blue, green,
    indigo, blue,   green, yellow,
    blue,   green,  yellow, orange,
    green,  yellow, orange, red },

  { indigo, blue, green, yellow,
    blue, green, yellow, orange,
    green, yellow, orange, red,
    yellow, orange, red, violet },

  { blue, green, yellow, orange,
    green, yellow, orange, red,
    yellow, orange, red, violet,
    orange, red, violet, indigo },

  { green, yellow, orange, red,
    yellow, orange, red, violet,
    orange, red, violet, indigo,
    red, violet, indigo, blue },

  { yellow, orange, red, violet,
    orange, red, violet, indigo,
    red, violet, indigo, blue,
    violet, indigo, blue, green },

  { orange, red, violet, indigo,
    red, violet, indigo, blue,
    violet, indigo, blue, green,
    indigo, blue, green, yellow },

  { red, violet, indigo, blue,
    violet, indigo, blue, green,
    indigo, blue, green, yellow,
    blue, green, yellow, orange }
};

uint16_t custom_animation_length = (sizeof(custom_animation_lut) / sizeof(custom_animation_lut[0]));    //The number of frames in the above array
uint16_t custom_animation_framerate = 200;                                                              //Time (in mS) between frames - Feel free to tweak this!

//****************************************************************************************
//Our setup function runs once on power up of the Hackpack it initialises the whole system
void setup()
{
  init_system();

  block_scale = 1;
  block_glow = 0;
  block_jitter = 0;
}

//***************************************************************************
//Our loop function runs in a loop all the time while our Hackpack is powered
void loop()
{
  update_display();
}
