#pragma once
#include "PhysicsEntity.h"

class Tile : public PhysicsEntity {
private:
	Texture* texture;
	const float tileWidth = 48.0f;
	const float tileHeight = 48.0f;

public:
	Tile(std::string fileName, int type);
	~Tile();

	bool HasCollision();
	void Render();
	void Update();
};