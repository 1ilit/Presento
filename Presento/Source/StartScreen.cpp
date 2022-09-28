#include "StartScreen.h"

StartScreen::StartScreen() {
	input = InputMgr::Instance();

	start = new Button("gift_box.png", 72, 72, Graphics::Instance()->winWidth * 0.5f, Graphics::Instance()->winHeight * 0.5f);
	start->Scale(Vector2(2.0f, 2.0f));

	info = new Button("info_button.png", 72, 72, Graphics::Instance()->winWidth * 0.94f, Graphics::Instance()->winHeight * 0.94f);
	info->Scale(Vector2(0.8f, 0.8f));

	startClicked = false;

}

StartScreen::~StartScreen() {
	InputMgr::Release();

	delete start;
	start = NULL;

	delete info;
	info = NULL;

}

void StartScreen::HandleInput() {

}


bool StartScreen::Started() {
	return start->WasClicked() || input->KeyReleased(SDL_SCANCODE_RETURN);
}

void StartScreen::SetFalse() {
	start->SetClicked(false);
}

void StartScreen::Update() {

	HandleInput();
	input->Update();
	info->Update();
	start->Update();
}

void StartScreen::Render() {
	start->Render();
	info->Render();
}