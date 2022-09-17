#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "GameManager.h"

int main(int argc, char* args[]) {

	GameManager* game = GameManager::Instance();

	game->Run();

	GameManager::Release();
	game = NULL;

	return 0;
}