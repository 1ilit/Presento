#pragma once
#include "Tile.h"

Tile::Tile(std::string fileName, int type) {
	
	texture = new Texture(fileName, (int)(type-1)*tileWidth, 0, (int)tileWidth, (int)tileHeight);
	texture->Parent(this);

	if (type != 8 && type != 9 && type != 12 && type != 13)
		AddCollider(Vector2(tileWidth, tileHeight));

}

Tile::~Tile() {
	delete texture;
	texture = NULL; 
}

bool Tile::IsColliding() {
	return collider != NULL;
}

void Tile::Update() {
	texture->Update();
}

void Tile::Render() {
	texture->Render();
}