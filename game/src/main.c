#include "raylib.h"
#include "player.h"
#include "platforms.h"
#include "collision.h"

typedef enum {
    LOGO, 
    TITLE, 
    GAMEPLAY, 
    ENDING
} gameScreen;


int main() {
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "platformer_v2");

    gameScreen screen = LOGO;

    playerInfo player = {0};
    startPlayer(&player);
    // int blankMap[MAP_WIDTH][MAP_HEIGHT] = {0};

    int framesCounter = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        float deltaTime = GetFrameTime();

        switch (screen) {
            case LOGO:
                framesCounter++;
                if (framesCounter > 180) {
                    screen = TITLE;
                    framesCounter = 0;
                }
                break;
            case TITLE:
                framesCounter++;
                if (IsKeyPressed(KEY_ENTER)) 
                    screen = GAMEPLAY;
                break;
            case GAMEPLAY:
                updatePlayer(&player, deltaTime);
                // if (playerTileCollide(&player))
                //     screen = ENDING;
                // platformCollision(&player, &platforms, deltaTime);
                if (IsKeyPressed(KEY_ENTER)) 
                    screen = ENDING;
                break;
            case ENDING:
                framesCounter++;
                if (IsKeyPressed(KEY_ENTER)) 
                    screen = TITLE;
                break;
            default: 
                break;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        switch (screen) {
            case LOGO:
                DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
                DrawText("WAIT for 3 seconds...", 290, 220, 20, GRAY);
                break;
            case TITLE:
                DrawText("TITLE SCREEN", 20, 20, 40, LIGHTGRAY);
                DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, GRAY);
                break;
            case GAMEPLAY:
                    drawPlatforms();
                    drawPlayer(&player);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, LIGHTGRAY);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, GRAY);
                break;
            case ENDING:
                DrawText("ENDING SCREEN", 20, 20, 40, LIGHTGRAY);
                DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, GRAY); 
                break;
            default: 
                break;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
