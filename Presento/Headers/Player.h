#pragma once
#include "PhysicsEntity.h"
#include "Texture.h"
#include "GUI.h"

class Player : public PhysicsEntity {
private:
	Texture* tex;

public:
	Player(Vector2 startPos);
	~Player();

	void Update();
	void Render();
};