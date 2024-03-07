#include "raylib.h"
#include "player.h"
#include "platforms.h"
#include "collision.h"

bool playerTileCollide(playerInfo *player) {
    int currentPlayerX = player->playerRec.x / TILE_WIDTH;
    int currentPlayerY = player->playerRec.y / TILE_HEIGHT;
    for (int belowAbove = currentPlayerY - 1; belowAbove <= currentPlayerY + 1; belowAbove++) {//Note that the - and + are to be set differently with differently sized player
        for (int leftRight = currentPlayerX - 1; leftRight <= currentPlayerX + 1; leftRight++) {
            if (leftRight >= 0 && leftRight < MAP_WIDTH && belowAbove >= 0 && belowAbove < MAP_HEIGHT) {
                if (firstMap[belowAbove][leftRight] == 1){
                    int currentTileX = (leftRight) * TILE_WIDTH;
                    int currentTileY = (belowAbove) * TILE_HEIGHT;
                    if (rectsoverlap(player, currentTileX, currentTileY, TILE_WIDTH, TILE_HEIGHT)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool rectsoverlap(playerInfo *player, int x2,int y2,int w2,int h2){
    if(player->playerRec.x >= (x2 + w2) || (player->playerRec.x + player->playerRec.width) <= x2) 
        return false;
    if(player->playerRec.y >= (y2 + h2) || (player->playerRec.y + player->playerRec.height) <= y2) 
       return false;

    return true;
}
