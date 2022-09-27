#include "Room.h"

Room::Room() {
	float currentx = 24.0f;
	float currenty = 24.0f;

	input = InputMgr::Instance();
	timer = Timer::Instance();

	for (int i = 0; i < mapHeight; i++) {

		for (int j = 0; j < mapWidth; j++) {
			if (m[i][j] != 0) {
				map[i][j] = new Tile("house_tiles.png", m[i][j]);
				map[i][j]->Pos(Vector2(currentx, currenty));
			}
			currentx += 48.0f;
		}

		currenty += 48.0f;
		currentx = 24.0f;
	}

	closet = new Entity("closet.png");
	closet->Pos(Vector2(400.0f, 370.0f));

	door = new Entity("door.png");
	door->Pos(Vector2(800.0f, 370.0f));

	closetPanel = new Panel();
	closetPanel->Parent(this);
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

	delete closet;
	closet = NULL;

	delete closetPanel;
	closetPanel = NULL;
}

bool Room::Exited() {
	return exited;
}

void Room::Update(Player* p) {

	closetPanel->Update();
	door->Update();

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (map[i][j]->HasCollision()) {

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

				door->Pos(Vector2(door->Pos().x - velocity.x, door->Pos().y));
				closet->Pos(Vector2(closet->Pos().x - velocity.x,closet->Pos().y));
				
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

				door->Pos(Vector2(door->Pos().x + velocity.x, door->Pos().y));
				closet->Pos(Vector2(closet->Pos().x + velocity.x, closet->Pos().y));
				
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

	if (p->CheckCollision(door) && input->KeyReleased(SDL_SCANCODE_RETURN)) {
		exited = true;
	}

	if (p->CheckCollision(closet) && input->KeyReleased(SDL_SCANCODE_RETURN)) {
		showClosetPanel = true;
		std::cout << showClosetPanel<<"\n";
	}

	if (showClosetPanel && closetPanel->WasClosed()) {
		showClosetPanel = false;
		closetPanel->SetClosed();
	}

	closet->Update();

}

void Room::Render() {
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (map[i][j]) {
				map[i][j]->Render();
			}
		}
	}

	
	closet->Render();
	door->Render();

	if(showClosetPanel)
		closetPanel->Render();
}