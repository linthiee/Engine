#include "Game.h"

int main()
{
	Game* game = new Game();

	game->EngineInit(900, 800, "test");
	game->Run();

	delete game;

	return 0;
}