#pragma once
#include "CardScreen.h"

CardScreen::CardScreen() {
	input = InputMgr::Instance();
	timer = Timer::Instance();

	play = new Button("ach_button.png", 50, 32, Graphics::Instance()->winWidth * 0.5f, Graphics::Instance()->winHeight * 0.9f);
	play->Scale(Vector2(1.7f, 1.4f));
}

CardScreen::~CardScreen() {
	InputMgr::Release();

	Timer::Release();

	delete play;
	play = NULL;
}

bool CardScreen::GameStarted() {
	return play->WasClicked() || input->KeyReleased(SDL_SCANCODE_RETURN);
}

void CardScreen::SetFalse() {
	play->SetClicked(false);
}

void CardScreen::Update() {

	play->Update();
}

void CardScreen::Render() {

	play->Render();
}