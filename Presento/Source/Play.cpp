#include "Play.h"

Play::Play() {
	p = new Player(Vector2(102.0f, Graphics::Instance()->winHeight-200.0f));
	r = new Room();
}

Play::~Play() {
	delete p;
	p = NULL;

	delete r;
	r = NULL;
}


void Play::Update() {
	p->Update();
	r->Update(p);
}

void Play::Render() {
	r->Render();
	p->Render();
}