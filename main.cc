//Engine
#include "game.hh"
#include "settings.hh"

//main
int main()
{
    Engine::Game myGame{settings::windowWidth, settings::windowHeight, settings::fps, "Tetris project - WIP #5"};
    while(!myGame.shouldGameClose()) myGame.tick();

    return EXIT_SUCCESS;
}


