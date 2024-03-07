#include "raylib.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 15
#define TILE_WIDTH 32
#define TILE_HEIGHT 32

extern int firstMap[MAP_HEIGHT][MAP_WIDTH];

typedef struct {
    Rectangle rect;
    int blocking;
    Color color;
} platformsInfo;

void drawPlatforms();
