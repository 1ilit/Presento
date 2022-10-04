#pragma once
#include "PhysicsEntity.h"
#include "AnimatedTex.h"

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
		IN_AIR_L,
		CLIMBING
	};

	enum BuniColor {
		BLUE,
		PINK,
		PURPLE,
		YELLOW
	};

private:
	AnimatedTex* idleRBlue;
	AnimatedTex* idleLBlue;
	AnimatedTex* idleRPink;
	AnimatedTex* idleLPink;
	AnimatedTex* idleRPurple;
	AnimatedTex* idleLPurple;
	AnimatedTex* idleRYellow;
	AnimatedTex* idleLYellow;

	AnimatedTex* jumpingRBlue;
	AnimatedTex* jumpingLBlue;
	AnimatedTex* jumpingRPink;
	AnimatedTex* jumpingLPink;
	AnimatedTex* jumpingRPurple;
	AnimatedTex* jumpingLPurple;
	AnimatedTex* jumpingRYellow;
	AnimatedTex* jumpingLYellow;

	AnimatedTex* walkingRBlue;
	AnimatedTex* walkingLBlue;
	AnimatedTex* walkingRPink;
	AnimatedTex* walkingLPink;
	AnimatedTex* walkingRPurple;
	AnimatedTex* walkingLPurple;
	AnimatedTex* walkingRYellow;
	AnimatedTex* walkingLYellow;

	AnimatedTex* inAirRBlue;
	AnimatedTex* inAirLBlue;
	AnimatedTex* inAirRPink;
	AnimatedTex* inAirLPink;
	AnimatedTex* inAirRPurple;
	AnimatedTex* inAirLPurple;
	AnimatedTex* inAirRYellow;
	AnimatedTex* inAirLYellow;

	AnimatedTex* climbingBlue;
	AnimatedTex* climbingPink;
	AnimatedTex* climbingPurple;
	AnimatedTex* climbingYellow;

	State currentState = IDLE_R;
	BuniColor currentColor = BLUE;
	bool stop = false;
	
public:

	Player(Vector2 startPos);
	~Player();

	void StopClimbing();
	void ResumeClimbing();
	void SetState(State state);
	void SetColor(BuniColor color);
	bool JumpAnimDone();
	void Update();
	void Render();
};