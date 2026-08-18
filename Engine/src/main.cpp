#include "BaseGame.h"

class Game : public BaseGame
{	
private:

public:
	Game() = default;
	~Game() = default;
	void Run()
	{
		if (!InIt())
		{
			return;
		}
		CreateWindow(800, 600, "Voke");
		while (!WindowShouldClose())
		{
			Render();

			SwapBuffers();

			glfwPollEvents();
		}
	}
};


int main(void)
{
	Game game = Game();

	game.Run();
}