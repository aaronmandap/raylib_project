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

int rightTile;
int leftTile;
int flag = 0;

void updatePlayer(playerInfo *player, float delta) {
    if (IsKeyDown(KEY_RIGHT)) {
        if (playerTileCollide(player, 1, 0)) {
            rightTile = floor(player->playerRec.x) + player->playerRec.width;
            if (rightTile % TILE_WIDTH != 0 && (player->playerRec.x + player->playerRec.width) <= rightTile) {
                rightTile -= rightTile % TILE_WIDTH;
            }
            if (player->playerRec.x + player->playerRec.width >= rightTile) {
                player->playerRec.x = rightTile - TILE_WIDTH;
            }
        }
        else {
            player->playerRec.x += PLAYER_HOR_SPD * delta;
        }
    }
    else if (IsKeyDown(KEY_LEFT)) {
        if (playerTileCollide(player, -1, 0)) {
            leftTile = floor(player->playerRec.x);
            if (leftTile % TILE_WIDTH != 0 && player->playerRec.x >= leftTile) {
                leftTile -= (leftTile % TILE_WIDTH) - TILE_WIDTH;
            }
            if (player->playerRec.x <= leftTile) {
                player->playerRec.x = leftTile;
            }
        }
        else {
            player->playerRec.x -= PLAYER_HOR_SPD * delta;
        }
    }
    if (IsKeyDown(KEY_UP)) 
        player->playerRec.y -= PLAYER_VER_SPD * delta;
    if (IsKeyDown(KEY_DOWN)) 
        player->playerRec.y += PLAYER_VER_SPD * delta;
}

void drawPlayer(playerInfo *player) {
    DrawRectangleRec(player->playerRec, BLUE);
    DrawText(TextFormat("x: %0.2f", player->playerRec.x), player->playerRec.x - 8, player->playerRec.y - 20, 10, BLACK);
    DrawText(TextFormat("y: %0.2f", player->playerRec.x), player->playerRec.x - 8, player->playerRec.y - 30, 10, BLACK);
    DrawText(TextFormat("right: %d", rightTile), player->playerRec.x - 8, player->playerRec.y - 40, 10, BLACK);
    DrawText(TextFormat("left: %d", leftTile), player->playerRec.x - 8, player->playerRec.y - 50, 10, BLACK);
    DrawText(TextFormat("flag: %d", flag), player->playerRec.x - 8, player->playerRec.y - 60, 10, BLACK);
}
