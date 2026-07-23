#include "game.h"
#include "config/config.h"
#include "world/world.h"
#include <time.h>
#include <stdio.h>
#include <raymath.h>
/**
 * GAME LOOP Implementation
 */

Game Game_Init(void)
{
    InitWindow(SCREEN_W, SCREEN_H, "World Hopper");
    SetTargetFPS(TARGET_FPS);
    SetRandomSeed((unsigned int)time(NULL));

    Game game = {0};
    Vector2 center = {WORLD_W / 2.0f, WORLD_H / 2.0f};
    game.player = Player_Create(center);

    game.camera = (Camera2D) {
        .target = game.player.position,
        .offset = { SCREEN_W / 2.0f, SCREEN_H / 2.0f },
        .rotation = 0.0f,
        .zoom = 1.0f,
    };

    return game;
}

static void Game_Update(Game *game, float dt)
{
    Player_Update(&game->player, dt);
    game->camera.target = game->player.position;
}

static void Game_DrawHUD(const Game *game)
{
    // Display players controls
    DrawText("Move with WASD and arrows", 10, 10, 20, RAYWHITE);
    
    // Display Current Position of the player (x,y)
    DrawText(
        TextFormat("Pos: %.0f, %.0f",
            game->player.position.x, game->player.position.y),10, 35, 20, LIGHTGRAY
        );

    // Draw FPs
    DrawFPS(SCREEN_W - 90, 10);
}


static void Game_Draw(const Game *game)
{
    BeginDrawing();
    ClearBackground((Color){ 30, 30, 40, 255 });
 
    BeginMode2D(game->camera);
        World_Draw();
        Player_Draw(&game->player);
        
    EndMode2D();
 
    Game_DrawHUD(game);
 
    EndDrawing();
}

bool Game_Frame(Game *game) {
    if (WindowShouldClose()) return false;

    Game_Update(game, GetFrameTime());
    Game_Draw(game);
    return true;
}


void Game_Shutdown(Game *game)
{
    (void) game;
    CloseWindow();
}