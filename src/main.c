#include "game/game.h"

int main(void){
    Game game = Game_Init();
 
    while (Game_Frame(&game)) { /* main loop */ }
    
    // Shutdown
    Game_Shutdown(&game);
    return 0;
}
