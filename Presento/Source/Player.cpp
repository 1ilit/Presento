#include "Player.h"

Player::Player(Vector2 startPos) {

	Pos(startPos);

	idleR = new AnimatedTex("idle_right.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	idleR->Parent(this);
	idleR->Pos(VEC2_ZERO);

	idleL = new AnimatedTex("idle_left.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	idleL->Parent(this);
	idleL->Pos(VEC2_ZERO);

	jumpingR = new AnimatedTex("jumping_right.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	jumpingR->WrapMode(AnimatedTex::wrap_mode::once);
	jumpingR->Parent(this);
	jumpingR->Pos(VEC2_ZERO);

	jumpingL = new AnimatedTex("jumping_left.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	jumpingR->WrapMode(AnimatedTex::wrap_mode::once);
	jumpingL->Parent(this);
	jumpingL->Pos(VEC2_ZERO);

	walkingR = new AnimatedTex("walking_right.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal);
	walkingR->Parent(this);
	walkingR->Pos(VEC2_ZERO);

	walkingL = new AnimatedTex("walking_left.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	walkingL->Parent(this);
	walkingL->Pos(VEC2_ZERO);

	inAirR = new AnimatedTex("in_air_right.png", 0, 0, 48, 48, 1, 0.6f, AnimatedTex::anim_d::horizontal);
	inAirR->Parent(this);
	inAirR->Pos(VEC2_ZERO);

	inAirL = new AnimatedTex("in_air_left.png", 0, 0, 48, 48, 1, 0.6f, AnimatedTex::anim_d::horizontal);
	inAirL->Parent(this);
	inAirL->Pos(VEC2_ZERO);

	AddCollider(idleR->ScaledDimensions());

}

Player::~Player() {

	delete idleR;
	idleR = NULL;

	delete idleL;
	idleL = NULL;

	delete jumpingR;
	jumpingR = NULL;

	delete jumpingL;
	jumpingL = NULL;

	delete walkingR;
	walkingR = NULL;

	delete walkingL;
	walkingL = NULL;

	delete inAirL;
	inAirL = NULL;
}

void Player::SetState(State state) {
	currentState = state;
}

bool Player::JumpAnimDone() {
	return !jumpingR->IsAnimating() && !jumpingL->IsAnimating();
}

void Player::Update() {
	switch (currentState) {
	case IDLE_R:
		idleR->Update();
		break;
	case IDLE_L:
		idleL->Update();
		break;
	case JUMPING_R:
		jumpingR->Update();
		break;
	case JUMPING_L:
		jumpingL->Update();
		break;
	case WALKING_R:
		walkingR->Update();
		break;
	case WALKING_L:
		walkingL->Update();
		break;
	case IN_AIR_R:
		inAirR->Update();
		break;
	case IN_AIR_L:
		inAirL->Update();
		break;
	default:
		break;
	}
}

void Player::Render() {
	switch (currentState) {
	case IDLE_R:
		idleR->Render();
		break;
	case IDLE_L:
		idleL->Render();
		break;
	case JUMPING_R:
		jumpingR->Render();
		break;
	case JUMPING_L:
		jumpingL->Render();
		break;
	case WALKING_R:
		walkingR->Render();
		break;
	case WALKING_L:
		walkingL->Render();
		break;
	case IN_AIR_R:
		inAirR->Render();
		break;
	case IN_AIR_L:
		inAirL->Render();
		break;
	default:
		break;
	}
}