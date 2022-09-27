#pragma once
#include "Player.h"

class Outside :public GameEntity {

private:
	const float gravity = 0.7f;
	bool isJumping = false;
	bool collidedTop = false;
	bool collidingBottom = false;
	bool collidingRight = false;
	bool collidingLeft = false;
	bool dirRight = true;
	float x = 0.0f;
	float y = 0.0f;
	float scrollOffset = 0.0f;
	Vector2 velocity = Vector2(4.0f, -15.0f);

public:
	Outside();
	~Outside();

	void Update(Player* p);
	void Render();
};


