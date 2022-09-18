#pragma once
#include "PhysicsEntity.h"

class Tile :public PhysicsEntity {
public:
	enum TILE_TYPE {
		GRASS = 1,
		DIRT = 2
	};
	Texture* texture;
	const int tileWidth = 48;
	const int tileHeight = 48;
	
public:
	Tile(std::string fileName, int type);
	~Tile();
	void Render();
	void Update();
};