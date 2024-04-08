#include "raylib.h"

typedef struct {
    float rightTile;
    float leftTile;
} tilePosition;

bool playerTileCollide(playerInfo *player, int offsetX, int offsetY);
bool checkCollision(playerInfo *player, int offsetX, int offsetY, int currentTileX, int currentTileY);
