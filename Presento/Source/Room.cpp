#include "Room.h"

Room::Room() {
	int currentx = 24;
	int currenty = 24;

	input = InputMgr::Instance();
	timer = Timer::Instance();

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
				if (p->CheckTopCollision(map[i][j])) {
					collidedTop = true;
					std::cout << "hit head\n";
				}
				if (p->CheckBottomCollision(map[i][j])) {
					collidedBottom = true;
					std::cout << "fell\n";
				}
			}
		}
	}
	if (input->KeyDown(SDL_SCANCODE_D)) {
		p->Translate(VEC2_RIGHT * speed * timer->DeltaTime(), world);
	}
	if (input->KeyDown(SDL_SCANCODE_A)) {
		p->Translate(-VEC2_RIGHT * speed * timer->DeltaTime(), world);
	}

	if (input->KeyPressed(SDL_SCANCODE_W)) {
		if (!isJumping) {
			isJumping = true;
			collidedBottom = false;
			yvel = 15.0f;
		}
	}

	if (isJumping || !collidedBottom)
	{
		p->Pos(Vector2(p->Pos().x, p->Pos().y - yvel));
		yvel -= gravity;
	}

	if (collidedBottom) {
		isJumping = false;
		yvel = 0.0f;
		collidedTop = false;
		p->Pos(Vector2(p->Pos().x, p->Pos().y));
		collidedBottom = false;
	}

	if (collidedTop)
	{	
		collidedBottom = false;
		yvel = -5.0f;
		//p->Pos(Vector2(p->Pos().x, p->Pos().y - yvel));
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