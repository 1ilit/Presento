#pragma once
#include "Tile.h"

Tile::Tile(std::string fileName, int tile) {
	
	if (tile >= 1 && tile <= 12) {
		texture = new Texture(fileName, (int)(tile - 1) * tileWidth, 0, (int)tileWidth, (int)tileHeight);
		texture->Parent(this);
	}
	if(tile>=13 && tile<=24) {

		texture = new Texture(fileName, (int)(tile - 13) * tileWidth, 48, (int)tileWidth, (int)tileHeight);
		texture->Parent(this);
	}

	if (tile != 8 && tile != 9 && tile != 12 && tile != 13 && !(tile <=24 && tile >=17))
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
