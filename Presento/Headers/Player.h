#pragma once
#include "PhysicsEntity.h"
#include "Texture.h"
#include "GUI.h"

class Player : public PhysicsEntity {
public:
	enum STATE {
		IDLE_R,
		IDLE_L,
		JUMPING,
		WALKING_R,
		WALKING_L 
	};
private:
	AnimatedTex* idleR;
	AnimatedTex* idleL;
	STATE currentState = IDLE_R;
	
public:

	Player(Vector2 startPos);
	~Player();

	void SetState(STATE state);
	void Update();
	void Render();
};