#include "Room.h"

Room::Room() {
	int currentx = 24;
	int currenty = 24;

	input = InputMgr::Instance();
	timer = Timer::Instance();

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			//std::cout << "x: " << currentx << " y: " << currenty << '|';
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
		//std::cout << std::endl;
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
				
				if (p->CheckTopCollision(map[i][j])) {
					collidedTop = true;
					//std::cout << "hit head\n";
				}
				if (p->CheckBottomCollision(map[i][j])) {
					collidingBottom = true;
					y = map[i][j]->Pos().y-48;
					//std::cout << "fell\n";
				}
				if(p->CheckRightCollision(map[i][j])) {
					x = map[i][j]->Pos().x;
					collidingRight = true;
					std::cout << "colliding from the right\n";
				}

				map[i][j]->	Update();
			}
		}
	}
	if (input->KeyDown(SDL_SCANCODE_D)) {
		if (collidingRight) {
			p->Pos(Vector2(x-48, p->Pos().y));
			collidingRight = false;
		}
		else {
			p->Pos(Vector2(p->Pos().x + 5, p->Pos().y));
		}//p->Translate(VEC2_RIGHT * speed * timer->DeltaTime(), world);
	}
	if (input->KeyDown(SDL_SCANCODE_A)) {
		if (collidingLeft) {
			p->Pos(Vector2(x, p->Pos().y));
		}
		else {
			p->Pos(Vector2(p->Pos().x - 5, p->Pos().y));
		}
		//p->Translate(-VEC2_RIGHT * speed * timer->DeltaTime(), world);
	}

	if (input->KeyPressed(SDL_SCANCODE_W)) {
		if (!isJumping) {
			isJumping = true;
			collidingBottom = false;
			yvel = 15.0f;
		}
	}

	if (isJumping || !collidingBottom)
	{
		p->Pos(Vector2(p->Pos().x, p->Pos().y - yvel));
		yvel -= gravity;
	} 

	if (collidingBottom) {
		p->Pos(Vector2(p->Pos().x, y));
		isJumping = false;
		yvel = 0.0f; 
		collidingBottom = false;
	}

	if (collidedTop)
	{	
		collidingBottom = false;
		yvel = -3.5f;
		collidedTop = false;
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