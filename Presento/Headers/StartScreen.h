#pragma once
#include "AnimatedTex.h"
#include "InputMgr.h"
#include "MathHelper.h"
#include "GUI.h"

class StartScreen : public GameEntity {
private:
	InputMgr* input;
	Texture* background;
	Button* start;
	Button* info;
	bool startClicked;

private:
	void HandleInput();

public:
	StartScreen();
	~StartScreen();

	void SetFalse();
	bool Started();
	void Update();
	void Render();
};