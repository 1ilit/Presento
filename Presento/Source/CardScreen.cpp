#pragma once
#include "CardScreen.h"

CardScreen::CardScreen() {
	input = InputMgr::Instance();
	timer = Timer::Instance();

	background = new Texture("black_screen.png");
	background->Parent(this);
	background->Pos(Vector2(Graphics::Instance()->winWidth * 0.5f, Graphics::Instance()->winHeight * 0.5f));
	background->Scale(Vector2(2.5f, 2.0f));

	play = new Button("ach_button.png", 50, 32, Graphics::Instance()->winWidth * 0.5f, Graphics::Instance()->winHeight * 0.9f);
	play->Scale(Vector2(1.7f, 1.4f));

	back = new Button("back.png", 64, 32, Graphics::Instance()->winWidth * 0.07f, Graphics::Instance()->winHeight * 0.07f);

	achievements = new Button("ach_button.png", 50, 32, Graphics::Instance()->winWidth * 0.92f, Graphics::Instance()->winHeight * 0.07f);
}

CardScreen::~CardScreen() {
	InputMgr::Release();

	Timer::Release();

	delete play;
	play = NULL;
}

bool CardScreen::GameStarted() {
	return play->wasClicked || input->KeyReleased(SDL_SCANCODE_RETURN);
}

void CardScreen::SetFalse() {
	play->wasClicked = false;
}

bool CardScreen::WentBack() {
	return back->wasClicked;
}

bool CardScreen::WentToAch() {
	return achievements->wasClicked;
}

void CardScreen::SetClicked(bool b) {
	back->wasClicked = b;
}

void CardScreen::SetAch(bool b) {
	achievements->wasClicked = b;
}

void CardScreen::HandleInput() {
	
}

void CardScreen::Update() {

	back->Update();
	achievements->Update();
	play->Update();
}

void CardScreen::Render() {
	background->Render();
	back->Render();
	achievements->Render();
	play->Render();
}