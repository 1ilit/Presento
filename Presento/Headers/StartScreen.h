#pragma once
#include "AnimatedTex.h"
#include "InputMgr.h"
#include "MathHelper.h"
#include "GUI.h"

class StartScreen : public GameEntity {
private:
	InputMgr* input;
	Button* start;
	bool startClicked;

public:
	StartScreen();
	~StartScreen();

	void SetFalse();
	bool Started();
	void Update();
	void Render();
};