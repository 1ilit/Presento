#pragma once
#include "PhysicsEntity.h"
#include "Texture.h"
#include "GUI.h"

class Player : public PhysicsEntity {
private:
	
	AnimatedTex* tex;
	
public:

	Player(Vector2 startPos);
	~Player();

	void Update();
	void Render();
};