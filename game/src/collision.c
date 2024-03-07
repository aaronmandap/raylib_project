#include "raylib.h"
#include "player.h"
#include "platforms.h"
#include "collision.h"

bool playerTileCollide(playerInfo *player) {
    int currentPlayerX = player->playerRec.x / TILE_WIDTH;
    int currentPlayerY = player->playerRec.y / TILE_HEIGHT;

    for (int belowAbove = currentPlayerY - 1; belowAbove <= currentPlayerY + 1; belowAbove++) {
        for (int leftRight = currentPlayerX - 1; leftRight <= currentPlayerX + 1; leftRight++) {
            if (leftRight >= 0 && leftRight < MAP_WIDTH && belowAbove >= 0 && belowAbove < MAP_HEIGHT) {
                if (firstMap[belowAbove][leftRight] == 1){
                    int currentTileX = (leftRight) * TILE_WIDTH;
                    int currentTileY = (belowAbove) * TILE_HEIGHT;
                    if (checkCollision(player, currentTileX, currentTileY)) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool checkCollision(playerInfo *player, int currentTileX, int currentTileY){
    if(player->playerRec.x >= (currentTileX + TILE_WIDTH) || (player->playerRec.x + player->playerRec.width) <= currentTileX) 
        return false;
    if(player->playerRec.y >= (currentTileY + TILE_HEIGHT) || (player->playerRec.y + player->playerRec.height) <= currentTileY) 
       return false;

    return true;
}
