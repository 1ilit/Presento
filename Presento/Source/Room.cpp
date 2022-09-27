#include "Room.h"

Room::Room() {
	float currentx = 24.0f;
	float currenty = 24.0f;

	input = InputMgr::Instance();
	timer = Timer::Instance();

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (m[i][j]!=0) {
				map[i][j] = new Tile("house_tiles.png", m[i][j]);
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

bool Room::Exited() {
	return exited;
}

void Room::Update(Player* p) {
	
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (map[i][j]->HasCollision()) {

				if (p->CheckTopCollision(map[i][j]) && m[i][j] != 16) {
					collidedTop = true;
					//std::cout << "top\n";
				}
				if (p->CheckBottomCollision(map[i][j]) && m[i][j] != 16) {
					collidingBottom = true;
					y = map[i][j]->Pos().y - 48.0f;
					//std::cout << "bot\n";
				}
				if (p->CheckRightCollision(map[i][j]) && m[i][j] != 16) {
					x = map[i][j]->Pos().x - 48.0f;
					collidingRight = true;
					//std::cout << "right\n";
				}
				if (p->CheckLeftCollision(map[i][j]) && m[i][j] != 16) {
					x = map[i][j]->Pos().x + 48.0f;
					collidingLeft = true;
					//std::cout << "left\n";
				}
				if (p->CheckCollision(map[i][j]) && m[i][j] == 16) {
					collidingWithDoor = true;
					//std::cout << collidingWithDoor << '\n';
				}

				map[i][j]->Update();
			}
		}
	}

	if (input->KeyDown(SDL_SCANCODE_D)) {
		dirRight = true;
		if (isJumping && p->JumpAnimDone())
			p->SetState(Player::State::IN_AIR_R);
		else {
			if(collidingBottom)
				p->SetState(Player::State::WALKING_R);
		}
			
		collidingLeft = false;
		if (collidingRight) {
			p->Pos(Vector2(x, p->Pos().y));
			collidingRight = false;
		}
		else {
			if (p->Pos().x < screenCenterX || scrollOffset>=screenCenterX) {
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
				scrollOffset += velocity.x;
			}
		}
	}
	else{
		if(collidingBottom && dirRight)
			p->SetState(Player::State::IDLE_R);
	}

	if (input->KeyDown(SDL_SCANCODE_A)) {
		dirRight = false;
		if (isJumping && p->JumpAnimDone())
			p->SetState(Player::State::IN_AIR_L);
		else {
			if(collidingBottom)
				p->SetState(Player::State::WALKING_L);
		}
			
		collidingRight = false;

		if (collidingLeft) {
			p->Pos(Vector2(x, p->Pos().y));
			collidingLeft = false;
		}

		else {
			if (p->Pos().x > screenCenterX || scrollOffset == 0.0f) {
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
				scrollOffset -= velocity.x;
			}
		}
	}
	else {
		if (collidingBottom && !dirRight)
			p->SetState(Player::State::IDLE_L);
	}

	if (input->KeyPressed(SDL_SCANCODE_W)) {
		if (!isJumping) {
			isJumping = true;
			collidingBottom = false;
			velocity.y = 15.0f;
		}

		if (isJumping) {
			if (dirRight)
				p->SetState(Player::State::JUMPING_R);
			else
				p->SetState(Player::State::JUMPING_L);
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

	if (collidingWithDoor && input->KeyReleased(SDL_SCANCODE_RETURN)) {
		exited = true;
		std::cout << "move screen\n";
	}

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