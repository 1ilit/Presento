#include "Room.h"

Room::Room() {
	float currentx = 24.0f;
	float currenty = 24.0f;

	input = InputMgr::Instance();
	timer = Timer::Instance();

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (m[i][j] == 1) {
				map[i][j] = new Tile("grass_tile.png", m[i][j]);
				map[i][j]->Pos(Vector2(currentx, currenty));
			}
			if (m[i][j] == 2) {
				map[i][j] = new Tile("grass_tile.png", m[i][j]);
				map[i][j]->Pos(Vector2(currentx, currenty));
			}
			currentx += 48.0f;
		}
		currenty += 48.0f;
		currentx = 24.0f;
	}

}

Room::~Room() {
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (map[i][j]) {
				delete map[i][j];
				map[i][j] = NULL;
			}
		}
	}
}

void Room::Update(Player* p) {

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (map[i][j]) {

				if (p->CheckTopCollision(map[i][j])) {
					collidedTop = true;
				}
				if (p->CheckBottomCollision(map[i][j])) {
					collidingBottom = true;
					y = map[i][j]->Pos().y - 48.0f;
				}
				if (p->CheckRightCollision(map[i][j])) {
					x = map[i][j]->Pos().x - 48.0f;
					collidingRight = true;
				}
				if (p->CheckLeftCollision(map[i][j])) {
					x = map[i][j]->Pos().x + 48.0f;
					collidingLeft = true;
				}

				map[i][j]->Update();
			}
		}
	}

	if (input->KeyDown(SDL_SCANCODE_D)) {
		if (collidingRight) {
			p->Pos(Vector2(x, p->Pos().y));
			collidingRight = false;
		}
		else {
			if (p->Pos().x < screenCenterX || p->tracker->Pos().x>=768.0f) {
				p->Pos(Vector2(p->Pos().x + velocity.x, p->Pos().y));
			}
			else {
				p->Pos(Vector2(screenCenterX, p->Pos().y));
				for (int i = 0; i < mapHeight; i++) {
					for (int j = 0; j < mapWidth; j++) {
						if (map[i][j]) {
							map[i][j]->Pos(Vector2(map[i][j]->Pos().x - velocity.x, map[i][j]->Pos().y));
						}
					}
				}
			}
			p->tracker->Pos(Vector2(p->tracker->Pos().x + velocity.x, p->tracker->Pos().y));
		}
	}
	if (input->KeyDown(SDL_SCANCODE_A)) {
		if (collidingLeft) {
			p->Pos(Vector2(x, p->Pos().y));
			collidingLeft = false;
		}
		else {
			if (p->Pos().x > screenCenterX || p->tracker->Pos().x <= screenCenterX) {
				p->Pos(Vector2(p->Pos().x - velocity.x, p->Pos().y));
			}
			else {
				p->Pos(Vector2(screenCenterX, p->Pos().y));

				for (int i = 0; i < mapHeight; i++) {
					for (int j = 0; j < mapWidth; j++) {
						if (map[i][j]) {
							map[i][j]->Pos(Vector2(map[i][j]->Pos().x + velocity.x, map[i][j]->Pos().y));
						}
					}
				}

			}
			p->tracker->Pos(Vector2(p->tracker->Pos().x - velocity.x, p->tracker->Pos().y));
		}
	}

	if (input->KeyPressed(SDL_SCANCODE_W)) {
			if (!isJumping) {
				isJumping = true;
				collidingBottom = false;
				velocity.y = 15.0f;
			}
		}

	if (isJumping || !collidingBottom) {
		p->Pos(Vector2(p->Pos().x, p->Pos().y - velocity.y));
		velocity.y -= gravity;
	}

	if (collidingBottom) {
			p->Pos(Vector2(p->Pos().x, y));
			isJumping = false;
			velocity.y = 0.0f;
			collidingBottom = false;
		}

	if (collidedTop) {
		collidedTop = false;
		collidingBottom = false;
		velocity.y = -3.5f;
	}

	//std::cout << "x: " << p->tracker->Pos().x << " y: " << p->tracker->Pos().y << " screenPos: " << mapWidth * 48 - screenCenterX << "\n";
}

void Room::Render() {
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (map[i][j]) {
				map[i][j]->Render();
			}
		}
	}
}