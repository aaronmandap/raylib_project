#include "raylib.h"
#include "player.h"
#include "platforms.h"

void platformCollision(playerInfo *player, platformsInfo platforms[], float deltaTime) {
    int hitPlatform = 0;
    for (int i = 0; i < MAX_PLATFORM_COUNT; i++) {
        platformsInfo *colPlatform = &platforms[i];
        Vector2 *colPlayer = &(player->position);

        if (colPlatform->blocking && 
            colPlatform->rect.x <= colPlayer->x && 
            colPlatform->rect.x + colPlatform->rect.width >= colPlayer->x &&
            colPlatform->rect.y >= colPlayer->y &&
            colPlatform->rect.y <= colPlayer->y + player->speed * deltaTime) 
        {
            hitPlatform = 1;
            player->speed = 0.0f;
            colPlayer->y = colPlatform->rect.y;
        }
    }

    if (!hitPlatform) {
        player->position.y += player->speed * deltaTime;
        player->speed += GRAVITY * deltaTime;
        player->canJump = false;
    } else 
        player->canJump = true;
} 
