#include "GameManager.h"
#include <time.h>

GameManager* GameManager::instance = NULL;

GameManager* GameManager::Instance() {
	if (instance == NULL)
		instance = new GameManager();

	return instance;
}

void GameManager::Release() {
	delete instance;
	instance = NULL;
}

GameManager::GameManager() {

	srand(time(0));

	quit = false;

	timer = Timer::Instance();

	graphics = Graphics::Instance();

	screenMgr = ScreenMgr::Instance();

	inputMgr = InputMgr::Instance();

	assetMgr = AssetMgr::Instance();

}

GameManager::~GameManager() {

	ScreenMgr::Release();
	screenMgr = NULL;

	AssetMgr::Release();
	assetMgr = NULL;

	InputMgr::Release();
	inputMgr = NULL;

	Timer::Release();
	timer = NULL;

}

void GameManager::EarlyUpdate() {
	mouse.Update();

	inputMgr->Update();

	screenMgr->Update();
}

void GameManager::Update() {
	timer->Reset();
}

void GameManager::Render() {
	graphics->ClearBackBuffer();

	screenMgr->Render();
}

void GameManager::LateUpdate() {
	inputMgr->UpdatePrevInput();

}

void GameManager::Run() {
	while (!quit) {
		timer->Update();

		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		if (timer->DeltaTime() >= 1.0f / frameRate) {

			graphics->Render();

			EarlyUpdate();
			Update();
			LateUpdate();
			Render();
		}
		mouse.Render();
	}
}
