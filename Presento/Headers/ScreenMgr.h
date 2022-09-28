#pragma once

#include "StartScreen.h"
#include "CardScreen.h"
#include "Room.h"

class ScreenMgr {
private:
	enum SCREEN {
		START,
		CARD,
		PLAY
	};

	static ScreenMgr* instance;

	StartScreen* startScreen;
	CardScreen* cardScreen;
	Room* room;

	SCREEN currentScreen=SCREEN::START;

public:
	bool started = false;

public:
	static ScreenMgr* Instance();
	static void Release();

	void Update();
	void Render();

private:
	ScreenMgr();
	~ScreenMgr();
};
