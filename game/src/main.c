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
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "platformer_v2");

    gameScreen screen = LOGO;

    playerInfo player = {0};
    initPlayer(&player);
    platformsInfo platforms[MAX_PLATFORM_COUNT] = {0};
    initPlatforms(platforms);

    unsigned int framesCounter = 0;
    // int gameResult = -1;
    bool gamePaused = false; 

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
                platformCollision(&player, platforms, deltaTime);
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
                if (!gamePaused) {
                    for (int i = 0; i < MAX_PLATFORM_COUNT; i++) {
                        DrawRectangleRec(platforms[i].rect, platforms[i].color);
                    }
                    DrawRectangleRec((Rectangle){player.position.x - 20, player.position.y -40, 40, 40}, RED);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, LIGHTGRAY);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, GRAY);
                }
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
