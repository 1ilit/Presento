#include "Play.h"

Play::Play() {
	player = new Player(Vector2(120.0f, Graphics::Instance()->winHeight-300.0f));
	room = new Room();
	outside = new Outside();
}

Play::~Play() {
	delete player;
	player = NULL;

	delete room;
	room = NULL;

	delete outside;
	outside = NULL;
}


void Play::Update() {
	player->Update();

	switch (currentWorld) {
	case ROOM:
		room->Update(player);
		if (room->Exited()) {
			player->Pos(Vector2(120.0f, Graphics::Instance()->winHeight - 300.0f));
			currentWorld = OUTSIDE;
		}
		break;
	case OUTSIDE:
		outside->Update(player);
		break;
	default:
		break;
	}
	
}

void Play::Render() {
	switch (currentWorld) {
	case ROOM:
		room->Render();
		break;
	case OUTSIDE:
		outside->Render();
		break;
	default:
		break;
	}

	player->Render();
}