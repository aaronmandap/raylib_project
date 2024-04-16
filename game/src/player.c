#include "raylib.h"
#include "player.h"
#include "collision.h"
#include "platforms.h"
#include "math.h"

void startPlayer(playerInfo *player) {
    player->playerRec = (Rectangle){400, 280, 32, 32};
    player->speed = 0;
    player->canJump = false;
}

void rectifyPosition(float *playerPosition, float *playerSize, char axis, int sign) {
    int tileSize = (axis == 'x') ? TILE_WIDTH : TILE_HEIGHT;
    int tileBorder = 0;

    if (sign == 1) {
        tileBorder = floor(*playerPosition) + *playerSize;

        if (tileBorder % tileSize != 0 && *playerPosition + *playerSize <= tileBorder) {
            tileBorder -= tileBorder % tileSize;
        }
        if (*playerPosition + *playerSize >= tileBorder) {
            *playerPosition = tileBorder - tileSize;
        }
    }
    else {
        tileBorder = floor(*playerPosition); 

        if (tileBorder % tileSize != 0 && *playerPosition >= tileBorder) {
            tileBorder -= (tileBorder % tileSize) - tileSize;
        }
        if (*playerPosition <= tileBorder) {
            *playerPosition = tileBorder;
        }
    }
}

void updatePlayer(playerInfo *player, float delta) {
    if (IsKeyDown(KEY_RIGHT)) {
        if (playerTileCollide(player, 1, 0)) {
            rectifyPosition(&player->playerRec.x, &player->playerRec.width, 'x', 1);
        }
        else {
            player->playerRec.x += PLAYER_HOR_SPD * delta;
        }
    }
    else if (IsKeyDown(KEY_LEFT)) {
        if (playerTileCollide(player, -1, 0)) {
            rectifyPosition(&player->playerRec.x, &player->playerRec.width, 'x', -1);
        }
        else {
            player->playerRec.x -= PLAYER_HOR_SPD * delta;
        }
    }

    if (IsKeyPressed(KEY_SPACE) && player->canJump == true) {
        player->playerRec.y -= PLAYER_VER_SPD * delta;
        player->canJump = false;
    }
    else if (playerTileCollide(player, 0, 1)) {
        rectifyPosition(&player->playerRec.y, &player->playerRec.height, 'y', 1);
        player->canJump = true;
    }
    else { 
        player->playerRec.y += GRAVITY * delta;
    }
}

void drawPlayer(playerInfo *player) {
    DrawRectangleRec(player->playerRec, BLUE);
    DrawText(TextFormat("x: %0.2f", player->playerRec.x), player->playerRec.x - 8, player->playerRec.y - 20, 10, BLACK);
    DrawText(TextFormat("y: %0.2f", player->playerRec.x), player->playerRec.x - 8, player->playerRec.y - 30, 10, BLACK);
}
