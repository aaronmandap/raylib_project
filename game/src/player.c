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
    if (IsKeyDown(KEY_UP)) 
        player->playerRec.y -= PLAYER_VER_SPD * delta;
    if (IsKeyDown(KEY_DOWN)) 
        player->playerRec.y += PLAYER_VER_SPD * delta;

    if (playerTileCollide(player)) {
        BeginDrawing();
        DrawText("Collision!", 640/2, 480/2, 40, RED);
        EndDrawing();
    }
}

void drawPlayer(playerInfo *player) {
    DrawRectangleRec(player->playerRec, BLUE);
}
