#include "raylib.h"
#include "player.h"

void initPlayer(playerInfo *player) {
    player->position = (Vector2){400, 280};
    player->speed = 0;
    player->canJump = false;
}

void updatePlayer(playerInfo *player, float delta) {
if (IsKeyDown(KEY_LEFT)) 
        player->position.x -= PLAYER_HOR_SPD * delta;
    if (IsKeyDown(KEY_RIGHT)) 
        player->position.x += PLAYER_HOR_SPD * delta;
    if (IsKeyDown(KEY_SPACE) && player->canJump) {
        player->speed = -PLAYER_JUMP_SPD;
        player->canJump = false;
    }
}
