#pragma once
#include "AnimatedTex.h"
#include "GUI.h"

class MenuScreen : public GameEntity {
private:
	InputMgr* input;
	Timer* timer;
	Texture* left;
	Texture* right;
	Button* lButton;
	Button* rButton;
	Button* back;
	Button* achievements;
	Button* play;
	Panel* panel[7];
	float scrollSpeed;
	int currentPanel;
	Texture* count;

private:
	void HandleInput();

public:
	MenuScreen();
	~MenuScreen();

	bool GameStarted();
	void SetFalse();
	bool WentBack();
	bool WentToAch();
	void SetClicked(bool b);
	void SetAch(bool b);

	void Update();
	void Render();
};