#pragma once
#include "Tile.h"

class TileMap : public GameEntity {
private:
	static const int mapHeight = 12;
	int mapWidth;
	std::vector<std::vector<Tile*>> map;

public:
	template <size_t rows, size_t cols>
	TileMap(int (&m)[rows][cols], int mapWidth);
	~TileMap();
	void TranslateX(float x);
	void Update();
	void Render();
};