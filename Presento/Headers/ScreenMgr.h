#pragma once

#include "StartScreen.h"
#include "CardScreen.h"
#include "Achievements.h"
#include "Play.h"

class ScreenMgr {
private:
	enum SCREEN {
		START,
		MENU,
		ACHIEVEMENTS,
		PLAY
	};

	static ScreenMgr* instance;

	StartScreen* startScreen;
	CardScreen* cardScreen;
	Achievements* achScreen;
	Play* playScreen;

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
