#include "Play.h"

Play::Play() {

	p = new Player(Vector2(32.0f, Graphics::Instance()->winHeight-30.0f));
	w = new World();
}

Play::~Play() {

	delete p;
	p = NULL;

	delete w;
	w = NULL;

}


void Play::Update() {
	p->Update();
	w->Update(p);
}

void Play::Render() {

	w->Render();
	p->Render();
}