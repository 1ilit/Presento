#include "Player.h"

Player::Player(Vector2 startPos) {

	Pos(startPos);

	tex = new Texture("neko-san.png");
	tex->Parent(this);
	tex->Pos(VEC2_ZERO);
	tex->Scale(Vector2(1.5f, 1.5f));

	tracker = new GameEntity(startPos);

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