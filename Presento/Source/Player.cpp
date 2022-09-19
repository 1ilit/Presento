#include "Player.h"

Player::Player(Vector2 startPos) {

	Pos(startPos);

	tex = new Texture("neko-san.png");
	tex->Parent(this);
	tex->Pos(VEC2_ZERO);
	tex->Scale(Vector2(1.5f, 1.5f));

	AddCollider(tex->ScaledDimensions());

}

Player::~Player() {

	delete tex;
	tex = NULL;
}

void Player::Update() {

}

void Player::Render() {
	tex->Render();
}

/*

cvsp

themes in odyssey

heroism
journey
civilization and primitiveness
man and the gods
values in greece

*/