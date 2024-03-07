#include "raylib.h"
#include "player.h"
#include "collision.h"

void startPlayer(playerInfo *player) {
    player->playerRec = (Rectangle){400, 280, 32, 32};
    player->speed = 0;
    player->canJump = false;
}

void updatePlayer(playerInfo *player, float delta) {
    if (IsKeyDown(KEY_LEFT)) 
        player->playerRec.x -= PLAYER_HOR_SPD * delta;
    if (IsKeyDown(KEY_RIGHT)) 
        player->playerRec.x += PLAYER_HOR_SPD * delta;
    // if (playerTileCollide(player))
    //     player->speed = 0.0f;
}

void drawPlayer(playerInfo *player) {
    DrawRectangleRec(player->playerRec, BLUE);
}
