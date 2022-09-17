#include "StartScreen.h"

StartScreen::StartScreen() {
	input = InputMgr::Instance();
	int thismap[18][22] = { {8,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 22; j++) {
			int x = thismap[i][j];
			if (x) {
				map[i][j] = new Texture("tileset_ph.png", (x - 1) * 32, 0, 32, 32);
			}

		}
	}

	dream = new Texture("dream.png");
	dream->Scale(Vector2(1.8f, 1.8f));
	dream->Pos(Vector2(Graphics::Instance()->winWidth * 0.4f, Graphics::Instance()->winHeight * 0.25f));

	chaser = new Texture("chaser.png");
	chaser->Scale(Vector2(1.7f, 1.7f));
	chaser->Pos(Vector2(Graphics::Instance()->winWidth * 0.6f, Graphics::Instance()->winHeight * 0.38f));

	start = new Button("start_button.png", 100, 40, Graphics::Instance()->winWidth * 0.5f, Graphics::Instance()->winHeight * 0.55f);
	start->Scale(Vector2(1.7f, 1.4f));

	info = new Button("info_button.png", 72, 72, Graphics::Instance()->winWidth * 0.94f, Graphics::Instance()->winHeight * 0.94f);
	info->Scale(Vector2(0.8f, 0.8f));

	ladder = new Texture("ladder.png");
	ladder->Scale(Vector2(1.0f, 1.02f));
	ladder->Pos(Vector2(Graphics::Instance()->winWidth * 0.265f, Graphics::Instance()->winHeight * 0.58f));

	yoonboon = new Texture("sitting_yoonboon.png");
	yoonboon->Scale(Vector2(2.0f, 2.0f));
	yoonboon->Pos(Vector2(Graphics::Instance()->winWidth * 0.265f, Graphics::Instance()->winHeight * 0.15f));

	yoobyoob = new Texture("hanging_yoobyoob.png");
	yoobyoob->Scale(Vector2(2.0f, 2.0f));
	yoobyoob->Pos(Vector2(Graphics::Instance()->winWidth * 0.735f, Graphics::Instance()->winHeight * 0.43f));

	startClicked = false;

	currentx = currenty = 16;
	HandleMap();
}

StartScreen::~StartScreen() {
	InputMgr::Release();

	delete dream;
	dream = NULL;

	delete chaser;
	chaser = NULL;

	delete start;
	start = NULL;

	delete info;
	info = NULL;

	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 22; j++) {
			if (map[i][j]) {
				delete map[i][j];
				map[i][j] = NULL;
			}
		}
	}

}

void StartScreen::HandleInput() {

}

void StartScreen::HandleMovement() {


}

void StartScreen::HandleMap() {
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 22; j++) {
			if (map[i][j]) {
				map[i][j]->Pos(Vector2(currentx, currenty));

			}currentx += 32;
		}
		currentx = 16;
		currenty += 32;
	}
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
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 22; j++) {
			if (map[i][j])
				map[i][j]->Render();
		}
	}
	dream->Render();
	chaser->Render();
	start->Render();
	info->Render();
	ladder->Render();
	yoonboon->Render();
	yoobyoob->Render();
}