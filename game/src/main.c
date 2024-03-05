#include "raylib.h"

typedef enum {
    LOGO, 
    TITLE, 
    GAMEPLAY, 
    ENDING
} gameScreen;

typedef struct {
    Vector2 position;
    float speed;
    bool canJump;
} playerInfo;

typedef struct {
    Rectangle rect;
    int blocking;
    Color color;
} envInfo;

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "platformer_v2");

    gameScreen screen = LOGO;

    int framesCounter = 0;
    // int gameResult = -1;
    bool gamePaused = false; 

    playerInfo player = {0};
    player.position = (Vector2){400, 280};
    player.speed = 0;
    player.canJump = false;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
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
                if (!gamePaused) {
                    // TODO: Gameplay logic
                }
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
                DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
                break;
            case GAMEPLAY:
                if (!gamePaused) {
                    // TODO: Gameplay logic
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
                }
                break;
            case ENDING:
                DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE); 
                break;
            default: 
                break;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
