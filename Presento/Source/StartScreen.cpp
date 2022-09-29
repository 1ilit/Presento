#include "StartScreen.h"

StartScreen::StartScreen() {
	input = InputMgr::Instance();

	start = new Button("gift_box.png", 72, 72, Graphics::Instance()->winWidth * 0.5f, Graphics::Instance()->winHeight * 0.5f);
	start->Scale(Vector2(2.0f, 2.0f));

	startClicked = false;

}

StartScreen::~StartScreen() {
	InputMgr::Release();

	delete start;
	start = NULL;

}

bool StartScreen::Started() {
	return start->WasClicked() || input->KeyReleased(SDL_SCANCODE_RETURN);
}

void StartScreen::SetFalse() {
	start->SetClicked(false);
}

void StartScreen::Update() {
	input->Update();
	start->Update();
}

void StartScreen::Render() {
	start->Render();
}