#ifndef GLOBALVARS_H_
#define GLOBALVARS_H_

#define MAX_LIVES 3
#define MAX_LEVEL 2

extern UINT16 g_player_score;
extern UINT8 g_level_current;
extern UINT16 g_level_coins;
extern UINT16 g_level_bullets;
extern UINT8 g_player_region;

typedef struct {
	UINT8 x;
	UINT8 y;
} ItemPos;

typedef enum {
	ITEM_COIN,
	ITEM_BULLET
} ItemType;

#endif