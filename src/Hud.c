#include "Banks/SetAutoBank.h"

#include <gbdk/platform.h>
#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"

#include "GlobalVars.h"

IMPORT_MAP (hud);
//IMPORT_MAP (hudDebug);

// Uncomment this next line for the debug HUD that shows nutmegs x and y position
// #define IS_DEBUG (true)

// global variables for every level

// saved last drawn values, to work out what to update on hud
static UINT8 lastLives = 0;
static UINT8 lastJewell = 0;


void Hud_Init() BANKED {
    INIT_HUD(hud);

    // prime the last values so they all get updated
    lastLives = g_lives + 1;
    lastJewell = g_jewell_counter + 1;
}

static UINT8 getTens (UINT8 full) {
    UINT8 t = 0 ;
    while (full > 9) {
        full -= 10;
        t ++;
    }
    return t;
}


void Hud_Update(void) BANKED {
    UINT8 tens;
    UINT8 ones;

    if (lastJewell != g_jewell_counter) {
        lastJewell = g_jewell_counter;
        tens = getTens(g_jewell_counter);
        ones = g_jewell_counter - (tens * 10);
        UPDATE_HUD_TILE (3, 0, 4 + tens);
        UPDATE_HUD_TILE (4, 0, 4 + ones);
    }

    if (lastLives != g_lives) {
        // update HUD lives
        lastLives = g_lives;
        for (UINT8 i = 0; i < MAX_LIVES; ++i) {
            UPDATE_HUD_TILE(16 + i, 0, i < g_lives ? 1 : 2);
        }
        //tens = getTens (g_lives);
        //ones = g_lives - (tens * 10);
        //UPDATE_HUD_TILE (3,0, 5 + tens);
        //UPDATE_HUD_TILE (4,0, 5 + ones);
    }
    
}

