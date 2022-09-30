#pragma once
#include "Inventory.h"

Inventory::Inventory() {
	emptyI = new Texture("empty_btn.png", 72, 0, 72, 72);
	emptyI->Scale(Vector2(0.75f, 0.75f));
	emptyI->Parent(this);
	emptyI->Pos(Vector2(48.0f, 52.0f));

	appleI = new Texture("apple_btn.png", 72, 0, 72, 72);
	appleI->Scale(Vector2(0.75f, 0.75f));
	appleI->Parent(this);
	appleI->Pos(Vector2(48.0f, 52.0f));

	bookI = new Texture("book_btn.png", 72, 0, 72, 72);
	bookI->Scale(Vector2(0.75f, 0.75f));
	bookI->Parent(this);
	bookI->Pos(Vector2(48.0f, 52.0f));

	fishI = new Texture("fish_btn.png", 72, 0, 72, 72);
	fishI->Scale(Vector2(0.75f, 0.75f));
	fishI->Parent(this);
	fishI->Pos(Vector2(48.0f, 52.0f));

	hatI = new Texture("hat_btn.png", 72, 0, 72, 72);
	hatI->Scale(Vector2(0.75f, 0.75f));
	hatI->Parent(this);
	hatI->Pos(Vector2(48.0f, 52.0f));

	ladderI = new Texture("ladder_btn.png", 72, 0, 72, 72);
	ladderI->Scale(Vector2(0.75f, 0.75f));
	ladderI->Parent(this);
	ladderI->Pos(Vector2(48.0f, 52.0f));

	pencilI = new Texture("pencil_btn.png", 72, 0, 72, 72);
	pencilI->Scale(Vector2(0.75f, 0.75f));
	pencilI->Parent(this);
	pencilI->Pos(Vector2(48.0f, 52.0f));
}

Inventory::~Inventory() {
	delete emptyI;
	emptyI = NULL;

	delete appleI;
	appleI = NULL;

	delete bookI;
	bookI = NULL;
	
	delete fishI;
	fishI = NULL;

	delete ladderI;
	ladderI = NULL;

	delete pencilI;
	pencilI = NULL;

	delete hatI;
	hatI = NULL;
}

Inventory::Item Inventory::GetCurrentItem() {
	return currentItem;
}

void Inventory::SetItem(Item item) {
	currentItem = item;
}

void Inventory::Update() {

}

void Inventory::Render() {
	switch (currentItem) {
	case EMPTY:
		emptyI->Render();
		break;
	case APPLE:
		appleI->Render();
		break;
	case BOOK:
		bookI->Render();
		break;
	case FISH:
		fishI->Render();
		break;
	case HAT:
		hatI->Render();
		break;
	case LADDER:
		ladderI->Render();
		break;
	case PENCIL:
		pencilI->Render();
		break;
	default:
		break;
	}
}
