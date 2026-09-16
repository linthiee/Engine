#include "BaseGame.h"
#include <Shape.h>

class Game : public BaseGame
{
public:	
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void Deinit() override;

private:

	Shape shape;
};


int main()
{
	Game* game = new Game();

	game->EngineInit(900, 800, "test");
	game->Run();

	delete game;

	return 0;
}

void Game::Init()
{
	shape = Shape(render, 3);

	shape.InitBuffer();
}

void Game::Update()
{
	shape.Draw();
}

void Game::Deinit()
{
}

Game::Game()
{
	shape = Shape();
}

Game::~Game()
{
}
