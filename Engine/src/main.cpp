#include "BaseGame.h"

int main()
{
	BaseGame* basegame = new BaseGame();

	basegame->Run();

	delete basegame;

	return 0;
}