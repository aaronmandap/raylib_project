#include "raylib.h"
#include "player.h"

playerInfo player;

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
