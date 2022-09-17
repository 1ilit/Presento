#pragma once
#include "Texture.h"
#include "GUI.h"

class Player : public GameEntity {
private:
	InputMgr* input;
	Timer* timer;

	Texture* tex;
	const float speed=350.0f;

	float yvel;
	const float gravity = 0.7f;
	const float groundHeight = Graphics::Instance()->winHeight-30.0f;
	bool isJumping = false;
	const float playerSpeed = 0.2f;

public:
	Player(Vector2 startPos);
	~Player();

	void Update();
	void Render();
};