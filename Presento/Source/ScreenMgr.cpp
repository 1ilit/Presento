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

	room = new Room();
}

ScreenMgr::~ScreenMgr() {
	delete startScreen;
	startScreen = NULL;

	delete cardScreen;
	cardScreen = NULL;

	delete room;
	room = NULL;

}

void ScreenMgr::Update() {
	switch (currentScreen) {
	case START:
		startScreen->Update();
		if (startScreen->Started()) {
			currentScreen = CARD;
			startScreen->SetFalse();
		}
		break;

	case CARD:
		cardScreen->Update();
		if (cardScreen->GameStarted()) {
			currentScreen = PLAY;
			cardScreen->SetFalse();
		}
		break;
	case PLAY:
		room->Update();
		break;
	}

}

void ScreenMgr::Render() {
	switch (currentScreen) {
	case START:
		startScreen->Render();
		started = true;
		break;
	case CARD:
		cardScreen->Render();
		break;
	case PLAY:
		room->Render();
		break;
	}
}