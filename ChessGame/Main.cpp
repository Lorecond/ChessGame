#include "Game.h"

int main()
{
    // Init Game
    Game game;

    // Game loop
    while (game.running())
    {
        // Update
        game.update();

        // Render
        game.render();
    }

    // End
    return 0;
}