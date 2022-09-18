#include "Room.h"

Room::Room() {
	int currentx = 24;
	int currenty = 24;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			if (m[i][j] == 1) {
				map[i][j] = new Tile("grass_tile.png", m[i][j]);
				map[i][j]->Pos(Vector2(currentx, currenty));
			}
			if (m[i][j] == 2) {
				map[i][j] = new Tile("grass_tile.png", m[i][j]);
				map[i][j]->Pos(Vector2(currentx, currenty));
			}
			currentx += 48;
		}
		currenty += 48;
		currentx = 24;
	}
}

Room::~Room() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			if (map[i][j]) {
				delete map[i][j];
				map[i][j] = NULL;
			}
		}
	}
}

void Room::Update(Player* p) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			if (map[i][j]) {
				map[i][j]->	Update();
				if (map[i][j]->CheckCollision(p)) {
					std::cout << "hit\n";
				}
			}
		}
	}
}

void Room::Render() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			if (map[i][j]) {
				map[i][j]->Render();
			}
		}
	}
}