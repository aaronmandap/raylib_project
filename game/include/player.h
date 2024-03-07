#include "raylib.h"
// #include "platforms.h"

#define GRAVITY 400
#define PLAYER_JUMP_SPD 350.0f
#define PLAYER_HOR_SPD 200.0f 
#define PLAYER_VER_SPD 200.0f 

typedef struct {
    Rectangle playerRec;
    float speed;
    bool canJump;
} playerInfo;

void updatePlayer(playerInfo *player, float delta);
void startPlayer(playerInfo *player);
void drawPlayer(playerInfo *player);
