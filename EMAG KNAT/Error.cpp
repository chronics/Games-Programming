#include "Error.h"

#include <iostream>
#include <SDL2\SDL.h>


void fatalError(std::string errorstring)
{
	int tempE;
	std::cout << errorstring << std::endl;
	std::cout << "Enter any key to quit...";

	std::cin >> tempE;
	SDL_Quit();
}