#pragma once
#include "Timer.h"
#include "Graphics.h"
#include "ScreenMgr.h"
#include "GUI.h"

class GameManager {
private:
	static GameManager* instance;
	const int frameRate = 60;
	bool quit;

	Timer* timer;
	SDL_Event e;

	Graphics* graphics;
	AssetMgr* assetMgr;
	InputMgr* inputMgr;

	ScreenMgr* screenMgr;

	Mouse mouse;

public:
	static GameManager* Instance();
	static void Release();

	void Run();

private:
	GameManager();
	~GameManager();

	void EarlyUpdate();
	void Update();
	void LateUpdate();
	void Render();
};

