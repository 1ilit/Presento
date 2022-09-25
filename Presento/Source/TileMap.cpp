#include "TileMap.h"

template <size_t rows, size_t cols>
TileMap::TileMap(int(&m)[rows][cols], int mapWidth) {
	int currentx = 24;
	int currenty = 24;

	for (int i = 0; i < mapHeight; i++) {
		std::vector<Tile*> temp;
		for (int j = 0; j < mapWidth; j++) {
			if (m[i][j] == 1) {
				temp.push_back(new Tile("grass_tile.png", m[i][j]));
				temp[j]->Pos(Vector2(currentx, currenty));
			}
			if (m[i][j] == 2) {
				temp.push_back(new Tile("grass_tile.png", m[i][j]));
				temp[j]->Pos(Vector2(currentx, currenty));
			}
			currentx += 48;
		}
		map.push_back(temp);
		temp.clear();

		currenty += 48;
		currentx = 24;
	}
}

TileMap::~TileMap() {
	for (int i = 0; i < mapHeight; i++) {
		for (unsigned int j = 0; j < map[0].size(); j++) {
			delete map[i][j];
			map[i][j] = NULL;
		}
	}
}

void TileMap::TranslateX(float x) {
	for (int i = 0; i < mapHeight; i++) {
		for (unsigned int j = 0; j < map[0].size(); j++) {
			map[i][j]->Pos(Vector2(map[i][j]->Pos().x+x, map[i][j]->Pos().y));
		}
	}
}

void TileMap::Update() {

}

void TileMap::Render() {
	for (int i = 0; i < mapHeight; i++) {
		for (unsigned int j = 0; j < map[0].size(); j++) {
			map[i][j]->Render();
		}
	}
}
