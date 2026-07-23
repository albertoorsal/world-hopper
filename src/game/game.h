#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "player/player.h"

typedef struct Game {
    Player   player;
    Camera2D camera;

} Game;

Game Game_Init(void);

// One frame: update logic and draw. Returns false if must exit.
bool Game_Frame(Game *game);

// Free resources and close window
void Game_Shutdown(Game *game);

#endif // GAME_H
