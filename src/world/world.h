#ifndef WORLD_MODULE_H
#define WORLD_MODULE_H

#include "raylib.h"

// -----------------------------------------------------------------------------
//  World: ground, borders and decorative obstacules .
// -----------------------------------------------------------------------------

#define WORLD_BORDER_THICK 4.0f

// Draw the complete map  (must be call it inside BeginMode2D)
void World_Draw(void);

#endif // WORLD_MODULE_H
