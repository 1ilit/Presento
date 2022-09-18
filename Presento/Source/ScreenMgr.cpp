#include "ScreenMgr.h"

ScreenMgr* ScreenMgr::instance = NULL;

ScreenMgr* ScreenMgr::Instance() {
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

	cardScreen = new CardScreen();

	achScreen = new Achievements();

	playScreen = new Play();
}

ScreenMgr::~ScreenMgr() {
	delete startScreen;
	startScreen = NULL;

	delete cardScreen;
	cardScreen = NULL;

	delete achScreen;
	achScreen = NULL;

}

void ScreenMgr::Update() {
	//std::cout << started<<'\n';

	switch (currentScreen) {
	case START:
		startScreen->Update();
		if (startScreen->Started()) {
			currentScreen = MENU;
			startScreen->SetFalse();
		}
		break;

	case MENU:
		cardScreen->Update();
		if (cardScreen->WentBack()) {
			currentScreen = START;
			cardScreen->SetClicked(false);
		}
		if (cardScreen->WentToAch()) {
			currentScreen = ACHIEVEMENTS;
			cardScreen->SetAch(false);
		}
		if (cardScreen->GameStarted()) {
			currentScreen = PLAY;
			cardScreen->SetFalse();
		}
		break;
	case ACHIEVEMENTS:
		achScreen->Update();
		if (achScreen->WentBack()) {
			currentScreen = MENU;
			achScreen->SetFalse();
		}
		break;
	case PLAY:
		playScreen->Update();
		break;
	}

}

void ScreenMgr::Render() {
	switch (currentScreen) {
	case START:
		startScreen->Render();
		started = true;
		break;
	case MENU:
		cardScreen->Render();
		break;
	case ACHIEVEMENTS:
		achScreen->Render();
		break;
	case PLAY:
		playScreen->Render();
		break;
	}
}