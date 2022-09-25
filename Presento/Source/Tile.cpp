#pragma once
#include "Tile.h"

Tile::Tile(std::string fileName, int type) {
	
	if (type >= 1 && type <= 12) {
		texture = new Texture(fileName, (int)(type - 1) * tileWidth, 0, (int)tileWidth, (int)tileHeight);
		texture->Parent(this);
	}
	if(type>=13 && type<=24) {

		texture = new Texture(fileName, (int)(type - 13) * tileWidth, 48, (int)tileWidth, (int)tileHeight);
		texture->Parent(this);
	}

	if (type != 8 && type != 9 && type != 12 && type != 13 && !(type<=24 && type>=16))
		AddCollider(Vector2(tileWidth, tileHeight));

}

Tile::~Tile() {
	if (texture) {
		delete texture;
		texture = NULL;
	}
}

bool Tile::HasCollision() {
	return collider!=NULL;
}

void Tile::Update() {
	if(texture)
		texture->Update();
}

void Tile::Render() {
	if(texture)
		texture->Render();
}
