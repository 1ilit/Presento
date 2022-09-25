#include "Player.h"

Player::Player(Vector2 startPos) {

	Pos(startPos);

	tex = new AnimatedTex("idle_right.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal);
	tex->Parent(this);
	tex->Pos(VEC2_ZERO);
	//tex->Scale(Vector2(1.2f, 1.2f));

	AddCollider(tex->ScaledDimensions());

}

Player::~Player() {

	delete tex;
	tex = NULL;
}

void Player::Update() {
	tex->Update();
}

void Player::Render() {
	tex->Render();
}