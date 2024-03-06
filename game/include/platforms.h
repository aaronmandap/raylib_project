#include "raylib.h"

#define MAX_PLATFORM_COUNT 5

typedef struct {
    Rectangle rect;
    int blocking;
    Color color;
} platformsInfo;

void initPlatforms(platformsInfo platforms[]);
