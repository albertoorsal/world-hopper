#include "world/world.h"
#include "config/config.h"

/**
 *  WORLD IMPLEMENTATION 
*/
static void DrawBlack(void) {

}


static void DrawBorder(void) {
    Rectangle bounds = { 0, 0, WORLD_W, WORLD_H};
    DrawRectangleLinesEx(bounds, 4, (Color){ 90, 120, 160, 255 });
}

void World_Draw(void) {
    DrawBorder();
}