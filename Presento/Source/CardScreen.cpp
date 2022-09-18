#pragma once
#include "CardScreen.h"

CardScreen::CardScreen() {
	input = InputMgr::Instance();
	timer = Timer::Instance();
	int start = 1056;

	panel[0] = new Panel(Vector2(Graphics::Instance()->winWidth * 0.5f, Graphics::Instance()->winHeight * 0.5f));

	for (int i = 1; i < 7; i++) {
		panel[i] = new Panel(Vector2(start, Graphics::Instance()->winHeight * 0.5f));
	}

	currentPanel = 1;

	scrollSpeed = 3000.0f;

	lButton = new Button("leftButton.png", 32, 32, Graphics::Instance()->winWidth * 0.07f, Graphics::Instance()->winHeight * 0.5f);
	lButton->Scale(Vector2(2.0f, 2.0f));

	rButton = new Button("rightButton.png", 32, 32, Graphics::Instance()->winWidth * 0.93f, Graphics::Instance()->winHeight * 0.5f);
	rButton->Scale(Vector2(2.0f, 2.0f));

	left = new Texture("square.png");
	left->Scale(Vector2(1.0f, 8.0f));
	left->Pos(Vector2(Graphics::Instance()->winWidth * 0.04f, Graphics::Instance()->winHeight * 0.5f));

	right = new Texture("square.png");
	right->Scale(Vector2(1.0f, 8.0f));
	right->Pos(Vector2(Graphics::Instance()->winWidth * 0.96f, Graphics::Instance()->winHeight * 0.5f));

	play = new Button("ach_button.png", 50, 32, Graphics::Instance()->winWidth * 0.5f, Graphics::Instance()->winHeight * 0.9f);
	play->Scale(Vector2(1.7f, 1.4f));

	back = new Button("back.png", 64, 32, Graphics::Instance()->winWidth * 0.07f, Graphics::Instance()->winHeight * 0.07f);

	achievements = new Button("ach_button.png", 50, 32, Graphics::Instance()->winWidth * 0.92f, Graphics::Instance()->winHeight * 0.07f);
}

CardScreen::~CardScreen() {
	InputMgr::Release();

	Timer::Release();

	for (int i = 0; i < 7; i++) {
		delete panel[i];
		panel[i] = NULL;
	}

	delete lButton;
	lButton = NULL;

	delete rButton;
	rButton = NULL;

	delete right;
	right = NULL;

	delete left;
	left = NULL;

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
	if (lButton->wasClicked) {
		if (panel[currentPanel - 1]->Pos().x < (Graphics::Instance()->winWidth * 0.5f + 704)) {
			panel[currentPanel - 1]->Translate(VEC2_RIGHT * scrollSpeed * timer->DeltaTime(), world);
		}
		if (panel[currentPanel - 2]->Pos().x < Graphics::Instance()->winWidth * 0.5 - 50) {
			panel[currentPanel - 2]->Translate(VEC2_RIGHT * scrollSpeed * timer->DeltaTime(), world);
		}
		else {
			currentPanel--;
			lButton->wasClicked = false;
		}
	}
	if (rButton->wasClicked) {
		if (panel[currentPanel - 1]->Pos().x > -Graphics::Instance()->winWidth * 0.5f) {
			panel[currentPanel - 1]->Translate(-VEC2_RIGHT * scrollSpeed * timer->DeltaTime(), world);
		}
		if (panel[currentPanel]->Pos().x > Graphics::Instance()->winWidth * 0.5) {
			panel[currentPanel]->Translate(-VEC2_RIGHT * scrollSpeed * timer->DeltaTime(), world);
		}
		else {
			currentPanel++;
			rButton->wasClicked = false;
		}
	}
}

void CardScreen::Update() {
	HandleInput();
	if (currentPanel == 1)
		rButton->Update();
	if (currentPanel == 7)
		lButton->Update();
	if (currentPanel > 1 && currentPanel < 7) {
		rButton->Update();
		lButton->Update();
	}
	back->Update();
	achievements->Update();
	play->Update();
}

void CardScreen::Render() {
	for (int i = 0; i < 7; i++)
		panel[i]->Render();

	left->Render();
	right->Render();

	if (currentPanel != 1)
		lButton->Render();

	if (currentPanel != 7)
		rButton->Render();

	back->Render();
	achievements->Render();
	play->Render();
}