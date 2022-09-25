#include "Player.h"

Player::Player(Vector2 startPos) {

	Pos(startPos);

	idleR = new AnimatedTex("idle_right.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal);
	idleR->Parent(this);
	idleR->Pos(VEC2_ZERO);
	//tex->Scale(Vector2(1.2f, 1.2f));

	idleL = new AnimatedTex("idle_left.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal);
	idleL->Parent(this);
	idleL->Pos(VEC2_ZERO);

	AddCollider(idleR->ScaledDimensions());

}

Player::~Player() {

	delete idleR;
	idleR = NULL;
}

void Player::SetState(STATE state) {
	currentState = state;
}

void Player::Update() {
	switch (currentState) {
	case IDLE_R:
		idleR->Update();
		break;
	case IDLE_L:
		idleL->Update();
		break;
	case JUMPING:
		break;
	case WALKING_R:
		break;
	case WALKING_L:
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
	case JUMPING:
		break;
	case WALKING_R:
		break;
	case WALKING_L:
		break;
	default:
		break;
	}
}