#include "game.h"
#include "config/config.h"
#include "world/world.h"
#include <time.h>
#include <stdio.h>
#include <raymath.h>
/**
 * GAME LOOP Implementation
 */
static void Game_Draw(const Game *game);

Game Game_Init(void)
{
    InitWindow(SCREEN_W, SCREEN_H, "World Hopper");
    SetTargetFPS(TARGET_FPS);
    SetRandomSeed((unsigned int)time(NULL));

    Game game = { 0 };
    game.camera.zoom = 1.0f;
    return game;
}

bool Game_Frame(Game *game)
{
    if(WindowShouldClose()) return false;

    Game_Draw(game);
    return true;
}

void Game_Shutdown(Game *game)
{
    (void) game;
    CloseWindow();
}

static void Game_Draw(const Game *game)
{
    BeginDrawing();
    ClearBackground((Color){ 30, 30, 40, 255 });
    BeginMode2D(game->camera);
    World_Draw();
    EndMode2D();
    EndDrawing();
}