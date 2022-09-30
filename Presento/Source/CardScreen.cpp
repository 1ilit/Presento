#pragma once
#include "CardScreen.h"

CardScreen::CardScreen() {
	input = InputMgr::Instance();
	timer = Timer::Instance();

	part1 = new Texture("Happy Birthday, Buni!", "ARCADE_N.TTF", 18, {255, 255, 255, 255});
	part1->Pos(Vector2(Graphics::Instance()->winWidth*0.5f, 150.0f));
	part1->Parent(this);

	part2 = new Texture("I left a little gift in your room.", "ARCADE_N.TTF", 18, { 255, 255, 255, 255 });
	part2->Pos(Vector2(Graphics::Instance()->winWidth * 0.5f, 200.0f));
	part2->Parent(this);

	part3 = new Texture("Hope you'll like it.", "ARCADE_N.TTF", 18, { 255, 255, 255, 255 });
	part3->Pos(Vector2(Graphics::Instance()->winWidth * 0.5f, 250.0f));
	part3->Parent(this);

	part4 = new Texture("- Ubi <3", "ARCADE_N.TTF", 18, { 255, 255, 255, 255 });
	part4->Pos(Vector2(Graphics::Instance()->winWidth * 0.5f, 300.0f));
	part4->Parent(this);

	play = new Button("start_btn.png", 220, 72, Graphics::Instance()->winWidth * 0.5f, Graphics::Instance()->winHeight * 0.9f);
	play->Scale(Vector2(0.8f, 0.8f));
}

CardScreen::~CardScreen() {
	InputMgr::Release();

	Timer::Release();

	delete play;
	play = NULL;
}

bool CardScreen::GameStarted() {
	return play->WasClicked() || (tracker >= 3 * delay2 && input->KeyReleased(SDL_SCANCODE_RETURN));
}

void CardScreen::SetFalse() {
	play->SetClicked(false);
}

void CardScreen::Update() {
	tracker += timer->DeltaTime();
	if (tracker >= delay1) {
		part1->Update();
	}
	if (tracker >= delay2) {
		part2->Update();
	}
	if (tracker >= 2*delay2) {
		part3->Update();
	}
	if (tracker >= 3*delay2) {
		part4->Update();
		play->Update();
	}

}

void CardScreen::Render() {
	if (tracker >= delay1) {
		part1->Render();
	}
	if (tracker >= delay2) {
		part2->Render();
	}
	if (tracker >= 2 * delay2) {
		part3->Render();
	}
	if (tracker >= 3 * delay2) {
		part4->Render();
		play->Render();
	}
	
}