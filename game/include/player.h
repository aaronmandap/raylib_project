#include "raylib.h"
#include <stdio.h>

#define GRAVITY 400
#define PLAYER_JUMP_SPD 350.0f
#define PLAYER_HOR_SPD 200.0f 

typedef struct {
    Vector2 position;
    float speed;
    bool canJump;
} playerInfo;

void updatePlayer(playerInfo *player, float delta);
