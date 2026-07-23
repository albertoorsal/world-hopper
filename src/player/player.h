#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player {
    Vector2 position;   // position pixel in theworld
    float   radius;     // collision raiuds / draw
    float   speed;      // speed pixles peer second
} Player;


// Create a player with defautl values and getting position.
Player Player_Create(Vector2 startPos);


// Update position for input and delta time

void Player_Update(Player *player, float dt);


// Draw player (must be calle it inside BeginMode2D)
void Player_Draw(const Player *player);

#endif // PLAYER_H