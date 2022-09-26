#pragma once
#include "PhysicsEntity.h"
#include "Texture.h"
#include "GUI.h"

class Player : public PhysicsEntity {
public:
	enum State {
		IDLE_R,
		IDLE_L,
		JUMPING_R,
		JUMPING_L,
		WALKING_R,
		WALKING_L,
		IN_AIR_R,
		IN_AIR_L
	};

private:
	AnimatedTex* idleR;
	AnimatedTex* idleL;
	AnimatedTex* jumpingR;
	AnimatedTex* jumpingL;
	AnimatedTex* walkingR;
	AnimatedTex* walkingL;
	AnimatedTex* inAirR;
	AnimatedTex* inAirL;

	State currentState = IDLE_R;
	
public:

	Player(Vector2 startPos);
	~Player();

	void SetState(State state);
	bool JumpAnimDone();
	void Update();
	void Render();
};