#include "Player.h"

Player::Player(Vector2 startPos) {

	Pos(startPos);

	//idle

	idleRBlue = new AnimatedTex("idle_right_blue.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	idleRBlue->Parent(this);
	idleRBlue->Pos(VEC2_ZERO);
		 
	idleLBlue = new AnimatedTex("idle_left_blue.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	idleLBlue->Parent(this);
	idleLBlue->Pos(VEC2_ZERO);

	idleRPink = new AnimatedTex("idle_right_pink.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	idleRPink->Parent(this);
	idleRPink->Pos(VEC2_ZERO);
		 
	idleLPink = new AnimatedTex("idle_left_pink.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	idleLPink->Parent(this);
	idleLPink->Pos(VEC2_ZERO);

	idleRPurple= new AnimatedTex("idle_right_purple.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	idleRPurple->Parent(this);
	idleRPurple->Pos(VEC2_ZERO);
		  
	idleLPurple= new AnimatedTex("idle_left_purple.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	idleLPurple->Parent(this);
	idleLPurple->Pos(VEC2_ZERO);

	idleRYellow = new AnimatedTex("idle_right_yellow.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	idleRYellow->Parent(this);
	idleRYellow->Pos(VEC2_ZERO);
		 
	idleLYellow = new AnimatedTex("idle_left_yellow.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	idleLYellow->Parent(this);
	idleLYellow->Pos(VEC2_ZERO);

	//jumping

	jumpingRBlue = new AnimatedTex("jumping_right_blue.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	jumpingRBlue->WrapMode(AnimatedTex::wrap_mode::once);
	jumpingRBlue->Parent(this);
	jumpingRBlue->Pos(VEC2_ZERO);
			
	jumpingLBlue = new AnimatedTex("jumping_left_blue.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	jumpingRBlue->WrapMode(AnimatedTex::wrap_mode::once);
	jumpingLBlue->Parent(this);
	jumpingLBlue->Pos(VEC2_ZERO);

	jumpingRPink = new AnimatedTex("jumping_right_pink.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	jumpingRPink->WrapMode(AnimatedTex::wrap_mode::once);
	jumpingRPink->Parent(this);
	jumpingRPink->Pos(VEC2_ZERO);
			
	jumpingLPink = new AnimatedTex("jumping_left_pink.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	jumpingRPink->WrapMode(AnimatedTex::wrap_mode::once);
	jumpingLPink->Parent(this);
	jumpingLPink->Pos(VEC2_ZERO);

	jumpingRPurple = new AnimatedTex("jumping_right_purple.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	jumpingRPurple->WrapMode(AnimatedTex::wrap_mode::once);
	jumpingRPurple->Parent(this);
	jumpingRPurple->Pos(VEC2_ZERO);
			
	jumpingLPurple = new AnimatedTex("jumping_left_purple.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	jumpingRPurple->WrapMode(AnimatedTex::wrap_mode::once);
	jumpingLPurple->Parent(this);
	jumpingLPurple->Pos(VEC2_ZERO);

	jumpingRYellow = new AnimatedTex("jumping_right_yellow.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	jumpingRYellow->WrapMode(AnimatedTex::wrap_mode::once);
	jumpingRYellow->Parent(this);
	jumpingRYellow->Pos(VEC2_ZERO);
			
	jumpingLYellow = new AnimatedTex("jumping_left_yellow.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	jumpingRYellow->WrapMode(AnimatedTex::wrap_mode::once);
	jumpingLYellow->Parent(this);
	jumpingLYellow->Pos(VEC2_ZERO);

	//walking

	walkingRBlue = new AnimatedTex("walking_right_blue.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal);
	walkingRBlue->Parent(this);
	walkingRBlue->Pos(VEC2_ZERO);
			
	walkingLBlue = new AnimatedTex("walking_left_blue.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	walkingLBlue->Parent(this);
	walkingLBlue->Pos(VEC2_ZERO);

	walkingRPink = new AnimatedTex("walking_right_pink.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal);
	walkingRPink->Parent(this);
	walkingRPink->Pos(VEC2_ZERO);
			
	walkingLPink = new AnimatedTex("walking_left_pink.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	walkingLPink->Parent(this);
	walkingLPink->Pos(VEC2_ZERO);

	walkingRPurple = new AnimatedTex("walking_right_purple.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal);
	walkingRPurple->Parent(this);
	walkingRPurple->Pos(VEC2_ZERO);
			
	walkingLPurple = new AnimatedTex("walking_left_purple.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	walkingLPurple->Parent(this);
	walkingLPurple->Pos(VEC2_ZERO);

	walkingRYellow = new AnimatedTex("walking_right_yellow.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal);
	walkingRYellow->Parent(this);
	walkingRYellow->Pos(VEC2_ZERO);
			
	walkingLYellow = new AnimatedTex("walking_left_yellow.png", 0, 0, 48, 48, 4, 0.6f, AnimatedTex::anim_d::horizontal);
	walkingLYellow->Parent(this);
	walkingLYellow->Pos(VEC2_ZERO);

	//in air

	inAirRBlue = new AnimatedTex("in_air_right_blue.png", 0, 0, 48, 48, 1, 0.6f, AnimatedTex::anim_d::horizontal);
	inAirRBlue->Parent(this);
	inAirRBlue->Pos(VEC2_ZERO);
		  
	inAirLBlue = new AnimatedTex("in_air_left_blue.png", 0, 0, 48, 48, 1, 0.6f, AnimatedTex::anim_d::horizontal);
	inAirLBlue->Parent(this);
	inAirLBlue->Pos(VEC2_ZERO);

	inAirRPink = new AnimatedTex("in_air_right_pink.png", 0, 0, 48, 48, 1, 0.6f, AnimatedTex::anim_d::horizontal);
	inAirRPink->Parent(this);
	inAirRPink->Pos(VEC2_ZERO);
		  
	inAirLPink = new AnimatedTex("in_air_left_pink.png", 0, 0, 48, 48, 1, 0.6f, AnimatedTex::anim_d::horizontal);
	inAirLPink->Parent(this);
	inAirLPink->Pos(VEC2_ZERO);

	inAirRPurple = new AnimatedTex("in_air_right_purple.png", 0, 0, 48, 48, 1, 0.6f, AnimatedTex::anim_d::horizontal);
	inAirRPurple->Parent(this);
	inAirRPurple->Pos(VEC2_ZERO);
		  
	inAirLPurple = new AnimatedTex("in_air_left_purple.png", 0, 0, 48, 48, 1, 0.6f, AnimatedTex::anim_d::horizontal);
	inAirLPurple->Parent(this);
	inAirLPurple->Pos(VEC2_ZERO);

	inAirRYellow = new AnimatedTex("in_air_right_yellow.png", 0, 0, 48, 48, 1, 0.6f, AnimatedTex::anim_d::horizontal);
	inAirRYellow->Parent(this);
	inAirRYellow->Pos(VEC2_ZERO);
		  
	inAirLYellow = new AnimatedTex("in_air_left_yellow.png", 0, 0, 48, 48, 1, 0.6f, AnimatedTex::anim_d::horizontal);
	inAirLYellow->Parent(this);
	inAirLYellow->Pos(VEC2_ZERO);
	

	AddCollider(idleRBlue->ScaledDimensions());

}

Player::~Player() {

	//idle
	delete idleRBlue;
	idleRBlue = NULL;

	delete idleLBlue;
	idleLBlue = NULL;

	delete idleRPink;
	idleRBlue = NULL;

	delete idleLPink;
	idleLBlue = NULL;

	delete idleRPurple;
	idleRPurple = NULL;

	delete idleLPurple;
	idleLPurple = NULL;

	delete idleRYellow;
	idleRYellow = NULL;

	delete idleLYellow;
	idleLYellow = NULL;

	//jumping
	delete jumpingRBlue;
	jumpingRBlue = NULL;

	delete jumpingLBlue;
	jumpingLBlue = NULL;

	delete jumpingRPink;
	jumpingRPink = NULL;

	delete jumpingLPink;
	jumpingLPink = NULL;

	delete jumpingRYellow;
	jumpingRYellow = NULL;

	delete jumpingLYellow;
	jumpingLYellow = NULL;

	delete jumpingRPurple;
	jumpingRPurple = NULL;

	delete jumpingLPurple;
	jumpingLPurple = NULL;

	//walking
	delete walkingRBlue;
	walkingRBlue = NULL;

	delete walkingLBlue;
	walkingLBlue = NULL;

	delete walkingRPink;
	walkingRPink = NULL;

	delete walkingLPink;
	walkingLPink = NULL;

	delete walkingRPurple;
	walkingRPurple = NULL;

	delete walkingLPurple;
	walkingLPurple = NULL;

	delete walkingRYellow;
	walkingRYellow = NULL;

	delete walkingLYellow;
	walkingLYellow = NULL;

	//in air
	delete inAirRBlue;
	inAirRBlue = NULL;

	delete inAirLBlue;
	inAirLBlue = NULL;

	delete inAirRPink;
	inAirRPink = NULL;

	delete inAirLPink;
	inAirLPink = NULL;

	delete inAirRPurple;
	inAirRPurple = NULL;

	delete inAirLPurple;
	inAirLPurple = NULL;

	delete inAirRYellow;
	inAirRYellow = NULL;

	delete inAirLYellow;
	inAirLYellow = NULL;
}

void Player::SetState(State state) {
	currentState = state;
}

void Player::SetColor(BuniColor color) {
	currentColor = color;
}

bool Player::JumpAnimDone() {
	return !jumpingRBlue->IsAnimating() && !jumpingLBlue->IsAnimating();
}

void Player::Update() {
	switch (currentState) {
	case IDLE_R:
		switch (currentColor) {
		case BLUE:
			idleRBlue->Update();
			break;
		case PINK:
			idleRPink->Update();
			break;
		case PURPLE:
			idleRPurple->Update();
			break;
		case YELLOW:
			idleRYellow->Update();
		default:
			break;
		}
		break;
	case IDLE_L:
		switch (currentColor) {
		case BLUE:
			idleLBlue->Update();
			break;
		case PINK:
			idleLPink->Update();
			break;
		case PURPLE:
			idleLPurple->Update();
			break;
		case YELLOW:
			idleLYellow->Update();
		default:
			break;
		}
		break;
	case JUMPING_R:
		switch (currentColor) {
		case BLUE:
			jumpingRBlue->Update();
			break;
		case PINK:
			jumpingRPink->Update();
			break;
		case PURPLE:
			jumpingRPurple->Update();
			break;
		case YELLOW:
			jumpingRYellow->Update();
		default:
			break;
		}
		break;
	case JUMPING_L:
		switch (currentColor) {
		case BLUE:
			jumpingLBlue->Update();
			break;
		case PINK:
			jumpingLPink->Update();
			break;
		case PURPLE:
			jumpingLPurple->Update();
			break;
		case YELLOW:
			jumpingLYellow->Update();
		default:
			break;
		}
		break;
	case WALKING_R:
		switch (currentColor) {
		case BLUE:
			walkingRBlue->Update();
			break;
		case PINK:
			walkingRPink->Update();
			break;
		case PURPLE:
			walkingRPurple->Update();
			break;
		case YELLOW:
			walkingRYellow->Update();
		default:
			break;
		}
		break;
	case WALKING_L:
		switch (currentColor) {
		case BLUE:
			walkingLBlue->Update();
			break;
		case PINK:
			walkingLPink->Update();
			break;
		case PURPLE:
			walkingLPurple->Update();
			break;
		case YELLOW:
			walkingLYellow->Update();
		default:
			break;
		}
		break;
	case IN_AIR_R:
		switch (currentColor) {
		case BLUE:
			inAirRBlue->Update();
			break;
		case PINK:
			inAirRPink->Update();
			break;
		case PURPLE:
			inAirRPurple->Update();
			break;
		case YELLOW:
			inAirRYellow->Update();
		default:
			break;
		}
		break;
	case IN_AIR_L:
		switch (currentColor) {
		case BLUE:
			inAirLBlue->Update();
			break;
		case PINK:
			inAirLPink->Update();
			break;
		case PURPLE:
			inAirLPurple->Update();
			break;
		case YELLOW:
			inAirLYellow->Update();
		default:
			break;
		}
		break;
	default:
		break;
	}
}


void Player::Render() {
	switch (currentState) {
	case IDLE_R:
		switch (currentColor) {
		case BLUE:
			idleRBlue->Render();
			break;
		case PINK:
			idleRPink->Render();
			break;
		case PURPLE:
			idleRPurple->Render();
			break;
		case YELLOW:
			idleRYellow->Render();
		default:
			break;
		}
		break;
	case IDLE_L:
		switch (currentColor) {
		case BLUE:
			idleLBlue->Render();
			break;
		case PINK:
			idleLPink->Render();
			break;
		case PURPLE:
			idleLPurple->Render();
			break;
		case YELLOW:
			idleLYellow->Render();
		default:
			break;
		}
		break;
	case JUMPING_R:
		switch (currentColor) {
		case BLUE:
			jumpingRBlue->Render();
			break;
		case PINK:
			jumpingRPink->Render();
			break;
		case PURPLE:
			jumpingRPurple->Render();
			break;
		case YELLOW:
			jumpingRYellow->Render();
		default:
			break;
		}
		break;
	case JUMPING_L:
		switch (currentColor) {
		case BLUE:
			jumpingLBlue->Render();
			break;
		case PINK:
			jumpingLPink->Render();
			break;
		case PURPLE:
			jumpingLPurple->Render();
			break;
		case YELLOW:
			jumpingLYellow->Render();
		default:
			break;
		}
		break;
	case WALKING_R:
		switch (currentColor) {
		case BLUE:
			walkingRBlue->Render();
			break;
		case PINK:
			walkingRPink->Render();
			break;
		case PURPLE:
			walkingRPurple->Render();
			break;
		case YELLOW:
			walkingRYellow->Render();
		default:
			break;
		}
		break;
	case WALKING_L:
		switch (currentColor) {
		case BLUE:
			walkingLBlue->Render();
			break;
		case PINK:
			walkingLPink->Render();
			break;
		case PURPLE:
			walkingLPurple->Render();
			break;
		case YELLOW:
			walkingLYellow->Render();
		default:
			break;
		}
		break;
	case IN_AIR_R:
		switch (currentColor) {
		case BLUE:
			inAirRBlue->Render();
			break;
		case PINK:
			inAirRPink->Render();
			break;
		case PURPLE:
			inAirRPurple->Render();
			break;
		case YELLOW:
			inAirRYellow->Render();
		default:
			break;
		}
		break;
	case IN_AIR_L:
		switch (currentColor) {
		case BLUE:
			inAirLBlue->Render();
			break;
		case PINK:
			inAirLPink->Render();
			break;
		case PURPLE:
			inAirLPurple->Render();
			break;
		case YELLOW:
			inAirLYellow->Render();
		default:
			break;
		}
		break;
	default:
		break;
	}
}