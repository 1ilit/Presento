#pragma once
#include "AnimatedTex.h"
#include "InputMgr.h"
#include "MathHelper.h"
#include "GUI.h"

class StartScreen : public GameEntity {
private:
	InputMgr* input;
	Texture* dream;
	Texture* chaser;
	Button* start;
	Button* info;
	Texture* ladder;
	Texture* yoonboon;
	Texture* yoobyoob;
	Texture* map[18][22];
	float currentx, currenty;
	bool startClicked;

private:
	void HandleInput();
	void HandleMap();
	void HandleMovement();

public:
	StartScreen();
	~StartScreen();

	void SetFalse();
	bool Started();
	void Update();
	void Render();
};