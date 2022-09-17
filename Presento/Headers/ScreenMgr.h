#pragma once

#include "StartScreen.h"
#include "MenuScreen.h"
#include "Achievements.h"
#include "Play.h"

class ScreenMgr {
private:
	enum SCREEN {
		start,
		menu,
		ach,
		play
	};

	static ScreenMgr* instance;

	StartScreen* startScreen;
	MenuScreen* menuScreen;
	Achievements* achScreen;
	Play* playScreen;

	SCREEN currentScreen;

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
