// Control for the pixels.

#include <avr/pgmspace.h>

uint32_t const sequence_table[][7] PROGMEM =
{
  //DECO BUILD RED
  
      {2000, SEQ_FAN_FADE_ON, 0, 100, 100, 100, 50},
      {6000, SEQ_FAN_FADE_OFF, 0, 100, 100, 100, 17},
      {10000, SEQ_FAN_STREAK_UP, 0, 100, 0, 0, 1},
/**
    {2000, SEQ_FAN_UNBUILD_DOWN, 0, 100, 100, 100, 3},
    {6000, SEQ_FAN_BUILD_UP, 0, 100, 100, 100, 1},
    {8000, SEQ_FAN_UNBUILD_UP, 0, 100, 100, 100, 1},
    **/
/**
 // now unbuild it
    {2000, SEQ_STAVE_BUILD_DOWN, 0, 100, 100, 100, 1},
    {2001, SEQ_STAVE_BUILD_DOWN, 2, 100, 100, 100, 1},
    {2002, SEQ_STAVE_BUILD_DOWN, 4, 100, 100, 100, 1},
    {2003, SEQ_STAVE_BUILD_DOWN, 6, 100, 100, 100, 1},
    
    {2004, SEQ_STAVE_BUILD_UP, 1, 100, 100, 100, 1},
    {2005, SEQ_STAVE_BUILD_UP, 3, 100, 100, 100, 1},
    {2006, SEQ_STAVE_BUILD_UP, 5, 100, 100, 100, 1},

    {3000, SEQ_STAVE_UNBUILD, 1, 100, 100, 100, 1},
    {3001, SEQ_STAVE_UNBUILD, 3, 100, 100, 100, 1},
    {3002, SEQ_STAVE_UNBUILD, 5, 100, 100, 100, 1},

    {3003, SEQ_STAVE_UNBUILD_DOWN, 0, 100, 100, 100, 1},
    {3004, SEQ_STAVE_UNBUILD_DOWN, 2, 100, 100, 100, 1},
    {3005, SEQ_STAVE_UNBUILD_DOWN, 4, 100, 100, 100, 1},
    {3006, SEQ_STAVE_UNBUILD_DOWN, 6, 100, 100, 100, 1},


    {4000, SEQ_STAVE_BUILD_DOWN, 0, 100, 100, 100, 1},
    {4001, SEQ_STAVE_BUILD_DOWN, 2, 100, 100, 100, 1},
    {4002, SEQ_STAVE_BUILD_DOWN, 4, 100, 100, 100, 1},
    {4003, SEQ_STAVE_BUILD_DOWN, 6, 100, 100, 100, 1},
    
    {4004, SEQ_STAVE_BUILD_UP, 1, 100, 100, 100, 1},
    {4005, SEQ_STAVE_BUILD_UP, 3, 100, 100, 100, 1},
    {4006, SEQ_STAVE_BUILD_UP, 5, 100, 100, 100, 1},

    {5000, SEQ_STAVE_UNBUILD, 1, 100, 100, 100, 1},
    {5001, SEQ_STAVE_UNBUILD, 3, 100, 100, 100, 1},
    {5002, SEQ_STAVE_UNBUILD, 5, 100, 100, 100, 1},

    {5003, SEQ_STAVE_UNBUILD_DOWN, 0, 100, 100, 100, 1},
    {5004, SEQ_STAVE_UNBUILD_DOWN, 2, 100, 100, 100, 1},
    {5005, SEQ_STAVE_UNBUILD_DOWN, 4, 100, 100, 100, 1},
    {5006, SEQ_STAVE_UNBUILD_DOWN, 6, 100, 100, 100, 1},


    {6000, SEQ_STAVE_BUILD_DOWN, 0, 100, 100, 100, 1},
    {6001, SEQ_STAVE_BUILD_DOWN, 2, 100, 100, 100, 1},
    {6002, SEQ_STAVE_BUILD_DOWN, 4, 100, 100, 100, 1},
    {6003, SEQ_STAVE_BUILD_DOWN, 6, 100, 100, 100, 1},
    
    {6004, SEQ_STAVE_BUILD_UP, 1, 100, 100, 100, 1},
    {6005, SEQ_STAVE_BUILD_UP, 3, 100, 100, 100, 1},
    {6006, SEQ_STAVE_BUILD_UP, 5, 100, 100, 100, 1},

    {7000, SEQ_STAVE_UNBUILD, 1, 100, 100, 100, 1},
    {7001, SEQ_STAVE_UNBUILD, 3, 100, 100, 100, 1},
    {7002, SEQ_STAVE_UNBUILD, 5, 100, 100, 100, 1},

    {7003, SEQ_STAVE_UNBUILD_DOWN, 0, 100, 100, 100, 1},
    {7004, SEQ_STAVE_UNBUILD_DOWN, 2, 100, 100, 100, 1},
    {7005, SEQ_STAVE_UNBUILD_DOWN, 4, 100, 100, 100, 1},
    {7006, SEQ_STAVE_UNBUILD_DOWN, 6, 100, 100, 100, 1},

**/

/**    

 
    {1000, SEQ_STAVE_BUILD_UP, 3, 100, 0, 0, 1},
    {1300, SEQ_STAVE_BUILD_UP, 2, 100, 0, 0, 1},
    {1301, SEQ_STAVE_BUILD_UP, 4, 100, 0, 0, 1},
    {1600, SEQ_STAVE_BUILD_UP, 1, 100, 0, 0, 1},
    {1601, SEQ_STAVE_BUILD_UP, 5, 100, 0, 0, 1},
    {1900, SEQ_STAVE_BUILD_UP, 0, 100, 0, 0, 1},
    {1901, SEQ_STAVE_BUILD_UP, 6, 100, 0, 0, 1},
    
    //DECO BUILD WHITE

    {2000, SEQ_STAVE_BUILD_UP, 3, 100, 100, 100, 1},
    {2300, SEQ_STAVE_BUILD_UP, 2, 100, 100, 100, 1},
    {2301, SEQ_STAVE_BUILD_UP, 4, 100, 100, 100, 1},
    {2600, SEQ_STAVE_BUILD_UP, 1, 100, 100, 100, 1},
    {2601, SEQ_STAVE_BUILD_UP, 5, 100, 100, 100, 1},
    {2900, SEQ_STAVE_BUILD_UP, 0, 100, 100, 100, 1},
    {2901, SEQ_STAVE_BUILD_UP, 6, 100, 100, 100, 1},
    
    //DECO BUILD RED
    
    {3000, SEQ_STAVE_BUILD_UP, 3, 100, 0, 0, 1},
    {3300, SEQ_STAVE_BUILD_UP, 2, 100, 0, 0, 1},
    {3301, SEQ_STAVE_BUILD_UP, 4, 100, 0, 0, 1},
    {3600, SEQ_STAVE_BUILD_UP, 1, 100, 0, 0, 1},
    {3601, SEQ_STAVE_BUILD_UP, 5, 100, 0, 0, 1},
    {3900, SEQ_STAVE_BUILD_UP, 0, 100, 0, 0, 1},
    {3901, SEQ_STAVE_BUILD_UP, 6, 100, 0, 0, 1},
    

    {5000, SEQ_STAVE_SHOOT_UP, 3, 100, 10, 0, 1},
    {5300, SEQ_STAVE_SHOOT_UP, 2, 100, 10, 0, 1},
    {5301, SEQ_STAVE_SHOOT_UP, 4, 100, 10, 0, 1},
    {5600, SEQ_STAVE_SHOOT_UP, 1, 100, 10, 0, 1},
    {5601, SEQ_STAVE_SHOOT_UP, 5, 100, 10, 0, 1},
    {5900, SEQ_STAVE_SHOOT_UP, 0, 100, 10, 0, 1},
    {5901, SEQ_STAVE_SHOOT_UP, 6, 100, 10, 0, 1},
  
  
    {6000, SEQ_STAVE_BUILD_UP, 3, 100, 0, 100, 1},
    {6300, SEQ_STAVE_BUILD_UP, 2, 100, 0, 100, 1},
    {6301, SEQ_STAVE_BUILD_UP, 4, 100, 0, 100, 1},
    {6600, SEQ_STAVE_BUILD_UP, 1, 100, 0, 100, 1},
    {6601, SEQ_STAVE_BUILD_UP, 5, 100, 0, 100, 1},
    {6900, SEQ_STAVE_BUILD_UP, 0, 100, 0, 100, 1},
    {6901, SEQ_STAVE_BUILD_UP, 6, 100, 0, 100, 1},
    
    {7000, SEQ_STAVE_SHOOT_UP, 3, 100, 10, 0, 1},
    {7300, SEQ_STAVE_SHOOT_UP, 2, 100, 10, 0, 1},
    {7301, SEQ_STAVE_SHOOT_UP, 4, 100, 10, 0, 1},
    {7600, SEQ_STAVE_SHOOT_UP, 1, 100, 10, 0, 1},
    {7601, SEQ_STAVE_SHOOT_UP, 5, 100, 10, 0, 1},
    {7900, SEQ_STAVE_SHOOT_UP, 0, 100, 10, 0, 1},
    {7901, SEQ_STAVE_SHOOT_UP, 6, 100, 10, 0, 1},
  

    {8000, SEQ_FAN_BUILD_UP, 0, 100, 100, 0, 2},
    
    // 10 SECONDS
  
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
    

    // 15 SECONDS

    {15000, SEQ_STAVE_UNBUILD, 2, 0, 60, 0, 1},
    {15500, SEQ_STAVE_UNBUILD, 3, 0, 80, 0, 1},
    {16000, SEQ_STAVE_UNBUILD, 4, 0, 100, 0, 1},
    {16500, SEQ_STAVE_UNBUILD, 5, 0, 120, 0, 1},
    {17000, SEQ_STAVE_UNBUILD, 6, 0, 140, 0, 1},
    // do a full fan build

    // 20 SECONDS

    {20000, SEQ_FAN_BUILD_UP, 0, 100, 100, 0, 5},
    {27000, SEQ_FAN_UNBUILD, 0, 100, 100, 0, 1},
    
    // 30 SECONDS RAINBOW
    
    
    {30000, SEQ_STAVE_BUILD_UP, 0, 100, 0, 0, 1},
    {30300, SEQ_STAVE_BUILD_UP, 1, 100, 50, 0, 1},
    {30301, SEQ_STAVE_BUILD_UP, 2, 100, 100, 0, 1},
    {30600, SEQ_STAVE_BUILD_UP, 3, 0, 10, 100, 1},
    {30601, SEQ_STAVE_BUILD_UP, 4, 0, 100, 10, 1},
    {30900, SEQ_STAVE_BUILD_UP, 5, 100, 0, 100, 1},
    {30901, SEQ_STAVE_BUILD_UP, 6, 100, 10, 40, 1},
    
   
    // now unbuild it
    {32000, SEQ_STAVE_UNBUILD, 0, 100, 100, 100, 1},
    {32001, SEQ_STAVE_UNBUILD, 2, 100, 100, 100, 1},
    {32500, SEQ_STAVE_UNBUILD, 4, 100, 100, 100, 1},
    {32900, SEQ_STAVE_UNBUILD, 6, 100, 100, 100, 1},
    
    {33000, SEQ_STAVE_BUILD_UP, 1, 100, 100, 100, 1},
    {33001, SEQ_STAVE_BUILD_UP, 3, 100, 100, 100, 1},
    {33100, SEQ_STAVE_BUILD_UP, 5, 100, 100, 100, 1},
    
    //UNBUILD WHITE
   
    {35000, SEQ_STAVE_UNBUILD, 0, 100, 100, 100, 1},
    {35500, SEQ_STAVE_UNBUILD, 1, 100, 100, 100, 1},
    {36000, SEQ_STAVE_UNBUILD, 2, 100, 100, 100, 1},
    {36500, SEQ_STAVE_UNBUILD, 3, 100, 100, 100, 1},
    {37000, SEQ_STAVE_UNBUILD, 4, 100, 100, 100, 1},
    {37500, SEQ_STAVE_UNBUILD, 5, 100, 100, 100, 1},
    {38000, SEQ_STAVE_UNBUILD, 6, 100, 100, 100, 1},
    /**
    
    // 40 SECONDS
    
    {120500, SEQ_STAVE_BUILD_UP, 1, 100, 10, 100, 1},
    {130000, SEQ_STAVE_BUILD_UP, 3, 100, 10, 100, 1},
    {130500, SEQ_STAVE_BUILD_UP, 5, 100, 10, 100, 1},
   
    {140000, SEQ_STAVE_UNBUILD, 0, 100, 100, 100, 1},
    {140500, SEQ_STAVE_UNBUILD, 1, 100, 100, 100, 1},
    {150000, SEQ_STAVE_UNBUILD, 2, 100, 100, 100, 1},
    {150500, SEQ_STAVE_UNBUILD, 3, 100, 100, 100, 1},
    {160000, SEQ_STAVE_UNBUILD, 4, 100, 100, 100, 1},
    {160500, SEQ_STAVE_UNBUILD, 5, 100, 100, 100, 1},
    {170000, SEQ_STAVE_UNBUILD, 6, 100, 100, 100, 1},
   /**
    
    {7000, SEQ_FAN_BUILD_UP, 0, 100, 100, 0, 5},
    {10000, SEQ_FAN_UNBUILD, 0, 100, 10, 40, 2},
    
    {12000, SEQ_STAVE_BUILD_UP, 0, 20, 0, 20, 1},
    {12250, SEQ_STAVE_BUILD_UP, 2, 20, 0, 20, 1},
    {12500, SEQ_STAVE_BUILD_UP, 4, 20, 0, 20, 1},
    {12501, SEQ_STAVE_BUILD_UP, 6, 20, 0, 20, 1},
    
    {14000, SEQ_FAN_UNBUILD, 0, 100, 10, 40, 2},
    
    /** 
      // 5 SECONDS
    {13000, SEQ_STAVE_BUILD_UP, 3, 0, 20, 0, 1},  **/
}; 



