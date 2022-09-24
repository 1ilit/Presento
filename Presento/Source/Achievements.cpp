#include "Achievements.h"

Achievements::Achievements() {
	back = new Button("back.png", 64, 32, (int)Graphics::Instance()->winWidth * 0.07, (int)Graphics::Instance()->winHeight * 0.07);
}

Achievements::~Achievements() {
	delete back;
	back = NULL;
}

bool Achievements::WentBack() {
	return back->wasClicked;
}

void Achievements::SetFalse() {
	back->wasClicked = false;
}

void Achievements::Update() {
	back->Update();
}

void Achievements::Render() {
	back->Render();
}