#pragma once
#include "AnimatedTex.h"
#include "GUI.h"

class CardScreen : public GameEntity {
private:
	InputMgr* input;
	Timer* timer;

	Texture* part1;
	Texture* part2;
	Texture* part3;
	Texture* part4;

	float delay1 = 0.5f;
	float delay2 = 1.5f;
	float tracker = 0.0f;

	Button* play;

public:
	CardScreen();
	~CardScreen();

	bool GameStarted();
	void SetFalse();

	void Update();
	void Render();
};