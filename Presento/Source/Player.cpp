#include "Player.h"

Player::Player(Vector2 startPos) {

	Pos(startPos);

	input = InputMgr::Instance();
	timer = Timer::Instance();

	tex = new Texture("neko-san.png");
	tex->Parent(this);
	tex->Pos(VEC2_ZERO);
	tex->Scale(Vector2(2.0f, 2.0f));

	AddCollider(tex->ScaledDimensions());

	yvel = 0.0f;
}

Player::~Player() {
	InputMgr::Release();

	Timer::Release();

	delete tex;
	tex = NULL;
}

void Player::Update() {

	//if (input->KeyDown(SDL_SCANCODE_D)) {
	//	Translate(VEC2_RIGHT*speed*timer->DeltaTime(), world);
	//}
	//if (input->KeyDown(SDL_SCANCODE_A)) {
	//	Translate(-VEC2_RIGHT*speed*timer->DeltaTime(), world);
	//}

	//if (input->KeyDown(SDL_SCANCODE_W)) {
	//	if (!isJumping) {
	//		isJumping = true;
	//		yvel = 15.0f;
	//	}
	//}

	//if (isJumping == true)
	//{
	//	Pos(Vector2(Pos().x, Pos().y - yvel));
	//	yvel -= gravity;
	//}

	//if (Pos().y >= groundHeight - 32) 
	//{
	//	isJumping = false;
	//	Pos(Vector2(Pos().x, groundHeight - 32));
	//}
	//	
	//if (Pos().y >= groundHeight) {
	//	Pos(Vector2(Pos().x, groundHeight));
	//}

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