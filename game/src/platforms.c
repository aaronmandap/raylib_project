#include "raylib.h"
#include "platforms.h"

void initPlatforms(platformsInfo platforms[]) {
    platforms[0].rect = (Rectangle){0, 0, 1000, 400};
    platforms[0].blocking = 0;
    platforms[0].color = LIGHTGRAY;

    platforms[1].rect = (Rectangle){0, 400, 1000, 200};
    platforms[1].blocking = 1;
    platforms[1].color = GRAY;
    

    // platformsInfo platforms[] = {
    //     {{0, 0, 1000, 400}, 0, LIGHTGRAY}, 
    //     {{0, 400, 1000, 200}, 1, GRAY}, 
    //     {{300, 200, 400, 10}, 1, GRAY}, 
    //     {{250, 300, 100, 10}, 1, GRAY}, 
    //     {{650, 300, 100, 10}, 1, GRAY}
    // };
}

