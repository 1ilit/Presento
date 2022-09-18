#include "StartScreen.h"

StartScreen::StartScreen() {
	input = InputMgr::Instance();

	background = new Texture("black_screen.png");
	background->Parent(this);
	background->Pos(Vector2(Graphics::Instance()->winWidth*0.5f, Graphics::Instance()->winHeight*0.5f));
	background->Scale(Vector2(2.5f, 2.0f));
	
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
	return start->wasClicked || input->KeyReleased(SDL_SCANCODE_RETURN);
}

void StartScreen::SetFalse() {
	start->wasClicked = false;
}

void StartScreen::Update() {

	HandleInput();
	input->Update();
	info->Update();
	start->Update();
}

void StartScreen::Render() {
	background->Render();
	start->Render();
	info->Render();
}