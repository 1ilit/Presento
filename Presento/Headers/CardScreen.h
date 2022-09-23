#pragma once
#include "AnimatedTex.h"
#include "GUI.h"

class CardScreen : public GameEntity {
private:
	InputMgr* input;
	Timer* timer;

	Texture* background;
	
	Button* back;
	Button* achievements;
	Button* play;

private:
	void HandleInput();

public:
	CardScreen();
	~CardScreen();

	bool GameStarted();
	void SetFalse();
	bool WentBack();
	bool WentToAch();
	void SetClicked(bool b);
	void SetAch(bool b);

	void Update();
	void Render();
};