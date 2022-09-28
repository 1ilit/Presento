#pragma once
#include "AnimatedTex.h"
#include "GUI.h"

class CardScreen : public GameEntity {
private:
	InputMgr* input;
	Timer* timer;

	Button* play;

public:
	CardScreen();
	~CardScreen();

	bool GameStarted();
	void SetFalse();

	void Update();
	void Render();
};