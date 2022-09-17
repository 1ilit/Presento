#include "ScreenMgr.h"

ScreenMgr* ScreenMgr::instance = NULL;

ScreenMgr* ScreenMgr::Instance() {
	//std::cout << "screen\n";

	if (!instance)
		instance = new ScreenMgr();

	return instance;
}

void ScreenMgr::Release() {
	delete instance;
	instance = NULL;
}

ScreenMgr::ScreenMgr() {
	startScreen = new StartScreen();

	menuScreen = new MenuScreen();

	achScreen = new Achievements();

	playScreen = new Play();

	currentScreen = start;
}

ScreenMgr::~ScreenMgr() {
	delete startScreen;
	startScreen = NULL;

	delete menuScreen;
	menuScreen = NULL;

	delete achScreen;
	achScreen = NULL;

}

void ScreenMgr::Update() {
	//std::cout << started<<'\n';

	switch (currentScreen) {
	case start:
		startScreen->Update();
		if (startScreen->Started()) {
			currentScreen = menu;
			startScreen->SetFalse();
		}
		break;

	case menu:
		menuScreen->Update();
		if (menuScreen->WentBack()) {
			currentScreen = start;
			menuScreen->SetClicked(false);
		}
		if (menuScreen->WentToAch()) {
			currentScreen = ach;
			menuScreen->SetAch(false);
		}
		if (menuScreen->GameStarted()) {
			currentScreen = play;
			menuScreen->SetFalse();
		}
		break;
	case ach:
		achScreen->Update();
		if (achScreen->WentBack()) {
			currentScreen = menu;
			achScreen->SetFalse();
		}
		break;
	case play:
		playScreen->Update();
		break;
	}

}

void ScreenMgr::Render() {
	switch (currentScreen) {
	case start:
		startScreen->Render();
		started = true;
		break;
	case menu:
		menuScreen->Render();
		break;
	case ach:
		achScreen->Render();
		break;
	case play:
		playScreen->Render();
		break;
	}
}