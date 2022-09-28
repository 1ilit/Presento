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

	closetPanel->AddAnimation("buni_blue", "idle_right_blue.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal, screenCenter.x - 125.0f, screenCenter.y);
	closetPanel->AddAnimation("buni_purple", "idle_right_purple.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal, screenCenter.x - 125.0f, screenCenter.y);
	closetPanel->AddAnimation("buni_pink", "idle_right_pink.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal, screenCenter.x - 125.0f, screenCenter.y);
	closetPanel->AddAnimation("buni_yellow", "idle_right_yellow.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal, screenCenter.x - 125.0f, screenCenter.y);

	closetPanel->GetAnimationByKey("buni_blue")->Scale(Vector2(2.0f, 2.0f));
	closetPanel->GetAnimationByKey("buni_purple")->Scale(Vector2(2.0f, 2.0f));
	closetPanel->GetAnimationByKey("buni_pink")->Scale(Vector2(2.0f, 2.0f));
	closetPanel->GetAnimationByKey("buni_yellow")->Scale(Vector2(2.0f, 2.0f));

	closetPanel->AddButton("blue", "player_blue.png", false, screenCenter.x + 62.5f, screenCenter.y - 90, 48, 48);
	closetPanel->AddButton("pink", "player_pink.png", false, screenCenter.x + 125.0f, screenCenter.y - 90, 48, 48);
	closetPanel->AddButton("yellow", "player_yellow.png", false, screenCenter.x + 62.5f, screenCenter.y + 90, 48, 48);
	closetPanel->AddButton("purple", "player_purple.png", false, screenCenter.x + 125.0f, screenCenter.y + 90, 48, 48);

	//std::cout << closetPanel->GetSize().x << " " << closetPanel->GetSize().y;
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

bool Room::ScreenDisabled() {
	return screenDisabled;
}

void Room::HandleCloset(Player* p) {
	closetPanel->Update();

	if (showClosetPanel) {
		closetPanel->Render();
		switch (currentBuni) {
		case BLUE:
			closetPanel->GetAnimationByKey("buni_blue")->Update();
			break;
		case PINK:
			closetPanel->GetAnimationByKey("buni_pink")->Update();
			break;
		case YELLOW:
			closetPanel->GetAnimationByKey("buni_yellow")->Update();
			break;
		case PURPLE:
			closetPanel->GetAnimationByKey("buni_purple")->Update();
			break;
		default:
			break;
		}
	}

	if (closetPanel->GetButtonByKey("blue")->WasClicked()) {
		currentBuni = BLUE;
		closetPanel->GetButtonByKey("blue")->SetClicked(false);
		p->SetColor(Player::BuniColor::BLUE);
	}
	if (closetPanel->GetButtonByKey("purple")->WasClicked()) {
		currentBuni = PURPLE;
		closetPanel->GetButtonByKey("purple")->SetClicked(false);
		p->SetColor(Player::BuniColor::PURPLE);
	}
	if (closetPanel->GetButtonByKey("yellow")->WasClicked()) {
		currentBuni = YELLOW;
		closetPanel->GetButtonByKey("yellow")->SetClicked(false);
		p->SetColor(Player::BuniColor::YELLOW);
	}
	if (closetPanel->GetButtonByKey("pink")->WasClicked()) {
		currentBuni = PINK;
		closetPanel->GetButtonByKey("pink")->SetClicked(false);
		p->SetColor(Player::BuniColor::PINK);
	}

}

void Room::Update(Player* p) {
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
		if (!screenDisabled) {
			dirRight = true;
			if (isJumping && p->JumpAnimDone())
				p->SetState(Player::State::IN_AIR_R);
			else {
				if (collidingBottom)
					p->SetState(Player::State::WALKING_R);
			}

			collidingLeft = false;
			if (collidingRight) {
				p->Pos(Vector2(x, p->Pos().y));
				collidingRight = false;
			}
			else {
				if (p->Pos().x < screenCenter.x || scrollOffset >= screenCenter.x) {
					p->Pos(Vector2(p->Pos().x + velocity.x, p->Pos().y));
				}
				else {
					p->Pos(Vector2(screenCenter.x, p->Pos().y));
					for (int i = 0; i < mapHeight; i++) {
						for (int j = 0; j < mapWidth; j++) {
							if (map[i][j]) {
								map[i][j]->Pos(Vector2(map[i][j]->Pos().x - velocity.x, map[i][j]->Pos().y));
							}
						}
					}

					door->Pos(Vector2(door->Pos().x - velocity.x, door->Pos().y));
					closet->Pos(Vector2(closet->Pos().x - velocity.x, closet->Pos().y));

					scrollOffset += velocity.x;
				}
			}
		}
	}
	else{
		if(collidingBottom && dirRight)
			p->SetState(Player::State::IDLE_R);
	}

	if (input->KeyDown(SDL_SCANCODE_A)) {
		if (!screenDisabled) {
			dirRight = false;
			if (isJumping && p->JumpAnimDone())
				p->SetState(Player::State::IN_AIR_L);
			else {
				if (collidingBottom)
					p->SetState(Player::State::WALKING_L);
			}

			collidingRight = false;

			if (collidingLeft) {
				p->Pos(Vector2(x, p->Pos().y));
				collidingLeft = false;
			}

			else {
				if (p->Pos().x > screenCenter.x || scrollOffset == 0.0f) {
					p->Pos(Vector2(p->Pos().x - velocity.x, p->Pos().y));
				}
				else {
					p->Pos(Vector2(screenCenter.x, p->Pos().y));

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
		screenDisabled = true;
		std::cout << showClosetPanel<<"\n";
	}

	if (showClosetPanel && closetPanel->WasClosed()) {
		showClosetPanel = false;
		screenDisabled = false;
		closetPanel->SetClosed();
	}

	closet->Update();

	HandleCloset(p);

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

	if (showClosetPanel) {
		closetPanel->Render();
		switch (currentBuni) {
		case BLUE:
			closetPanel->GetAnimationByKey("buni_blue")->Render();
			break;
		case PINK:
			closetPanel->GetAnimationByKey("buni_pink")->Render();
			break;
		case YELLOW:
			closetPanel->GetAnimationByKey("buni_yellow")->Render();
			break;
		case PURPLE:
			closetPanel->GetAnimationByKey("buni_purple")->Render();
			break;
		default:
			break;
		}
	}
		
}