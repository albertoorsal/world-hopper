#include "player/player.h"
#include "config/config.h"
#include "world/world.h"
#include "raymath.h"


Player Player_Create(Vector2 startPosition) {
    Player player = {
        .position = startPosition,
        .radius = 18.0f,
        .speed = 260.0f,
    };
    return player;
}


// Read input from keyboard and returns a Vector of direction (without normalize)
static Vector2 ReadInput(void) {
    Vector2 direction = {0.0f, 0.0f};

    // Direction update
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))    direction.y -= 1.0f;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))  direction.y += 1.0f;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  direction.x -= 1.0f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) direction.x += 1.0f;

    
    return direction;
}



// Mantain player inside the world limits (and off the border line)
static void ClampToWorld(Player *player) {
    float r = player->radius;
    float min = WORLD_BORDER_THICK;
    player->position.x = Clamp(player->position.x, r + min, WORLD_W - min - r);
    player->position.y = Clamp(player->position.y, r + min, WORLD_H - min - r);
}


// Update
void Player_Update(Player *player, float dt) {
    Vector2 direction = ReadInput();

    // normalize for diagonal be more faster
    if (direction.x != 0.0f || direction.y != 0.0f) {
        direction = Vector2Normalize(direction);
        Vector2 velocity = Vector2Scale(direction, player->speed * dt);
        player->position = Vector2Add(player->position, velocity);
    }
    ClampToWorld(player);
}


// Draw
void Player_Draw(const Player *player) {
    DrawCircleV(player->position, player->radius, (Color){ 90, 200, 120, 255 });
    DrawCircleLines(
        (int)player->position.x, (int)player->position.y, player->radius, DARKGREEN
    );
}




