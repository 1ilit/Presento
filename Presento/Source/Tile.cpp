#pragma once
#include "Tile.h"

Tile::Tile(std::string fileName, int type) {
	
	texture = (type==1) ? new Texture(fileName, 0, 0, tileWidth, tileHeight): 
		new Texture(fileName, tileWidth, 0, tileWidth, tileHeight);
	texture->Parent(this);

	AddCollider(Vector2((float)tileWidth, (float)tileHeight));
}

Tile::~Tile() {
	delete texture;
	texture = NULL;
}

void Tile::Update() {
	texture->Update();
}

void Tile::Render() {
	texture->Render();
}