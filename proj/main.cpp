#include <SFML/Graphics.hpp>
#include "Game.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game g1;
	try {
		g1.loop();
		//g1.main_loop();
	} 
		catch (const std::runtime_error& error)
		{
			std::cout<<error.what();
		}
		catch (const std::invalid_argument& error)
		{
			std::cout << error.what();
		}
	
	g1.~Game();
	system("pause");
	return 0;
}