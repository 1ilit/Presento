#include "Room.h"

Room::Room() {
	float currentx = 24.0f;
	float currenty = 24.0f;

	input = InputMgr::Instance();
	timer = Timer::Instance();

	p = new Player(Vector2(120.0f, Graphics::Instance()->winHeight - 300.0f));

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

	inv = new Inventory();

	ladder = new Entity("ladder.png");
	ladder->Pos(Vector2(p->Pos().x, 300.0f));

	chest = new Entity("chest.png");
	chest->Pos(Vector2(820.0f, 407.0f));

	shelf = new Entity("shelf.png");
	shelf->Pos(Vector2(250.0f, 170.0f));

	shelf2 = new Entity("shelf2.png");
	shelf2->Pos(Vector2(750.0f, 270.0f));

	bed = new Entity("bed.png");
	bed->Pos(Vector2(120.0f, 395.0f));

	closet = new Entity("closet.png");
	closet->Pos(Vector2(400.0f, 370.0f));

	dresser = new Entity("dresser.png");
	dresser->Pos(Vector2(620.0f, 385.0f));

	dresserPanel = new Panel();
	dresserPanel->Parent(this);
	
	dresserPanel->AddText("dresser_text", "ARCADE_N.TTF", "Pick an item", 14, screenCenter.x - 125.0f, 127);

	dresserPanel->AddButton("apple_btn", "apple_btn.png", true, screenCenter.x - 125.5f, screenCenter.y - 50, 72, 72);
	dresserPanel->AddButton("book_btn", "book_btn.png", true, screenCenter.x, screenCenter.y - 50, 72, 72);
	dresserPanel->AddButton("fish_btn", "fish_btn.png", true, screenCenter.x +125.0f, screenCenter.y - 50, 72, 72);
	dresserPanel->AddButton("hat_btn", "hat_btn.png", true, screenCenter.x - 125.5f, screenCenter.y + 50, 72, 72);
	dresserPanel->AddButton("ladder_btn", "ladder_btn.png", true, screenCenter.x, screenCenter.y + 50, 72, 72);
	dresserPanel->AddButton("pencil_btn", "pencil_btn.png", true, screenCenter.x + 125.0f, screenCenter.y + 50, 72, 72);

	door = new Entity("door.png");
	door->Pos(Vector2(1020.0f, 370.0f));

	closetPanel = new Panel();
	closetPanel->Parent(this);

	closetPanel->AddText("closet_text", "ARCADE_N.TTF", "Choose your outfit", 14, screenCenter.x - 85.0f, 127);

	closetPanel->AddAnimation("buni_blue", "idle_right_blue.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal, screenCenter.x - 125.0f, screenCenter.y);
	closetPanel->AddAnimation("buni_purple", "idle_right_purple.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal, screenCenter.x - 125.0f, screenCenter.y);
	closetPanel->AddAnimation("buni_pink", "idle_right_pink.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal, screenCenter.x - 125.0f, screenCenter.y);
	closetPanel->AddAnimation("buni_yellow", "idle_right_yellow.png", 0, 0, 48, 48, 4, 0.7f, AnimatedTex::anim_d::horizontal, screenCenter.x - 125.0f, screenCenter.y);

	closetPanel->GetAnimationByKey("buni_blue")->Scale(Vector2(2.0f, 2.0f));
	closetPanel->GetAnimationByKey("buni_purple")->Scale(Vector2(2.0f, 2.0f));
	closetPanel->GetAnimationByKey("buni_pink")->Scale(Vector2(2.0f, 2.0f));
	closetPanel->GetAnimationByKey("buni_yellow")->Scale(Vector2(2.0f, 2.0f));

	closetPanel->AddButton("blue", "player_blue.png", true, screenCenter.x + 32.5f, screenCenter.y - 50, 72, 72);
	closetPanel->AddButton("pink", "player_pink.png", true, screenCenter.x + 125.0f, screenCenter.y - 50, 72, 72);
	closetPanel->AddButton("yellow", "player_yellow.png", true, screenCenter.x + 32.5f, screenCenter.y + 50, 72, 72);
	closetPanel->AddButton("purple", "player_purple.png", true, screenCenter.x + 125.0f, screenCenter.y + 50, 72, 72);

	doorPanel = new SpeechBox();
	doorPanel->AddText("door_text", "ARCADE_N.TTF", "Coming soon...", 16, 230, 480);

	noKeyPanel = new SpeechBox();
	noKeyPanel->AddText("no_key_text", "ARCADE_N.TTF", "Key needed to open", 16, 260, 480);
}

Room::~Room() {

	InputMgr::Release();

	Timer::Release();

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

	delete door;
	door = NULL;

	delete doorPanel;
	doorPanel = NULL;

	delete dresser;
	dresser = NULL;

	delete dresserPanel;
	dresserPanel = NULL;

	delete p;
	p = NULL;

	delete chest;
	chest = NULL;

	delete bed;
	bed = NULL;

	delete inv;
	inv = NULL;

	delete shelf;
	shelf = NULL;

	delete shelf2;
	shelf2 = NULL;

	delete ladder;
	ladder = NULL;
}

bool Room::ScreenDisabled() {
	return screenDisabled;
}

void Room::HandleCloset() {
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
		}
	}
	if (showClosetPanel) {
		if (closetPanel->GetButtonByKey("blue")->WasClicked()) {
			currentBuni = BLUE;
			closetPanel->GetButtonByKey("blue")->SetClicked(false);
			p->SetColor(Player::BuniColor::BLUE);
		}
		else if (closetPanel->GetButtonByKey("purple")->WasClicked()) {
			currentBuni = PURPLE;
			closetPanel->GetButtonByKey("purple")->SetClicked(false);
			p->SetColor(Player::BuniColor::PURPLE);
		}
		else if (closetPanel->GetButtonByKey("yellow")->WasClicked()) {
			currentBuni = YELLOW;
			closetPanel->GetButtonByKey("yellow")->SetClicked(false);
			p->SetColor(Player::BuniColor::YELLOW);
		}
		else if (closetPanel->GetButtonByKey("pink")->WasClicked()) {
			currentBuni = PINK;
			closetPanel->GetButtonByKey("pink")->SetClicked(false);
			p->SetColor(Player::BuniColor::PINK);
		}
	}
	
}

void Room::HandleDresser() {
	dresserPanel->Update();

	if (showDresserPanel) {
		if (dresserPanel->GetButtonByKey("apple_btn")->WasClicked()) {
			inv->SetItem(Inventory::Item::APPLE);
			dresserPanel->GetButtonByKey("apple_btn")->SetClicked(false);
		}
		else if (dresserPanel->GetButtonByKey("book_btn")->WasClicked()) {
			inv->SetItem(Inventory::Item::BOOK);
			dresserPanel->GetButtonByKey("book_btn")->SetClicked(false);
		}
		else if (dresserPanel->GetButtonByKey("fish_btn")->WasClicked()) {
			inv->SetItem(Inventory::Item::FISH);
			dresserPanel->GetButtonByKey("fish_btn")->SetClicked(false);
		}
		else if (dresserPanel->GetButtonByKey("hat_btn")->WasClicked()) {
			inv->SetItem(Inventory::Item::HAT);
			dresserPanel->GetButtonByKey("hat_btn")->SetClicked(false);
		}
		else if (dresserPanel->GetButtonByKey("pencil_btn")->WasClicked()) {
			inv->SetItem(Inventory::Item::PENCIL);
			dresserPanel->GetButtonByKey("pencil_btn")->SetClicked(false);
		}
		else if (dresserPanel->GetButtonByKey("ladder_btn")->WasClicked()) {
			inv->SetItem(Inventory::Item::LADDER);
			dresserPanel->GetButtonByKey("ladder_btn")->SetClicked(false);
		}
	}
}

void Room::HandleClimbing() {
	if (isClimbing) {
		p->Pos(Vector2(p->Pos().x, p->Pos().y - velocity.x));
	}
	if (p->Pos().y + 24.0f >= ladder->Pos().y - 130.0f) {
		isClimbing = false;
	}
}

void Room::HandleChest() {
	if (p->CheckCollision(chest) && input->KeyReleased(SDL_SCANCODE_RETURN)) {
		if (!obtainedKey) {
			showNoKeyPanel = true;
		}
		else {
			showNoKeyPanel = false;
			openChest = true;
		}
	}
	else {
		if (!p->CheckCollision(chest))
			showNoKeyPanel = false;
	}
}

void Room::Update() {

	inv->Update();
	chest->Update();
	closet->Update();
	dresser->Update();
	door->Update();
	p->Update();

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

					if (showLadder) {
						ladder->Pos(Vector2(ladder->Pos().x - velocity.x, ladder->Pos().y));
					}

					shelf2->Pos(Vector2(shelf2->Pos().x - velocity.x, shelf2->Pos().y));
					shelf->Pos(Vector2(shelf->Pos().x - velocity.x, shelf->Pos().y));
					chest->Pos(Vector2(chest->Pos().x - velocity.x, chest->Pos().y));
					dresser->Pos(Vector2(dresser->Pos().x - velocity.x, dresser->Pos().y));
					bed->Pos(Vector2(bed->Pos().x - velocity.x, bed->Pos().y));
					door->Pos(Vector2(door->Pos().x - velocity.x, door->Pos().y));
					closet->Pos(Vector2(closet->Pos().x - velocity.x, closet->Pos().y));

					scrollOffset += velocity.x;
				}
				if (isClimbing) {
					isJumping = true;
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

					if (showLadder) {
						ladder->Pos(Vector2(ladder->Pos().x + velocity.x, ladder->Pos().y));
					}

					shelf2->Pos(Vector2(shelf2->Pos().x + velocity.x, shelf2->Pos().y));
					shelf->Pos(Vector2(shelf->Pos().x + velocity.x, shelf->Pos().y));
					chest->Pos(Vector2(chest->Pos().x + velocity.x, chest->Pos().y));
					dresser->Pos(Vector2(dresser->Pos().x + velocity.x, dresser->Pos().y));
					bed->Pos(Vector2(bed->Pos().x + velocity.x, bed->Pos().y));
					door->Pos(Vector2(door->Pos().x + velocity.x, door->Pos().y));
					closet->Pos(Vector2(closet->Pos().x + velocity.x, closet->Pos().y));

					scrollOffset -= velocity.x;
				}
				if (isClimbing) {
					isJumping = true;
				}
			}
		}
	}
	else {
		if (collidingBottom && !dirRight)
			p->SetState(Player::State::IDLE_L);
	}

	//ladder

	if(!showLadder)
		ladder->Pos(Vector2(p->Pos().x, ladder->Pos().y));

	//place the ladder
	if (input->KeyPressed(SDL_SCANCODE_P) && !showLadder) {
		showLadder = true;
	}

	//pick the ladder up
	if (input->KeyPressed(SDL_SCANCODE_O) && showLadder && p->CheckCollision(ladder)) {
		showLadder = false;
	}

	if (input->KeyPressed(SDL_SCANCODE_W)) {

		if (!showLadder || !(showLadder && p->CheckCollision(ladder))) {
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

	}

	if (input->KeyDown(SDL_SCANCODE_W)) {
		if (showLadder && p->CheckCollision(ladder)) {
			isClimbing = true;
			if(p->Pos().y+24.0f<=ladder->Pos().y-30.0f)
				p->Pos(Vector2(p->Pos().x, p->Pos().y - velocity.x));
			collidingBottom = false;
		}
	}
	if (input->KeyDown(SDL_SCANCODE_S)) {
		if (showLadder && p->CheckCollision(ladder)) {
			isClimbing = true;
			p->Pos(Vector2(p->Pos().x, p->Pos().y + velocity.x));
		}
	}



	if (isJumping || !collidingBottom && (!isClimbing && p->CheckCollision(ladder))) {
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

	//door

	if (p->CheckCollision(door) && input->KeyReleased(SDL_SCANCODE_RETURN)) {
		if(!showDoorPanel)
			showDoorPanel = true;
		else 
			showDoorPanel = false;
	}
	else {
		if (!p->CheckCollision(door))
			showDoorPanel = false;
	}
	
	//closet

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
	
	HandleCloset();

	//dresser

	if (p->CheckCollision(dresser) && input->KeyReleased(SDL_SCANCODE_RETURN)) {
		if (!showDresserPanel) {
			showDresserPanel= true;
			screenDisabled = true;
		}
	}
	if (showDresserPanel && dresserPanel->WasClosed()) {
		showDresserPanel = false;
		screenDisabled = false;
		dresserPanel->SetClosed();
	}

	HandleDresser();

	//chest
	HandleChest();


}

void Room::Render() {
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (map[i][j]) {
				map[i][j]->Render();
			}
		}
	}
	
	shelf2->Render();
	shelf ->Render();
	inv->Render();
	chest->Render();
	dresser->Render();
	bed->Render();
	closet->Render();
	door->Render();

	if(showLadder)
		ladder->Render();

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

	if(!screenDisabled)
		p->Render();

	if (showDoorPanel)
		doorPanel->Render();

	if (showDresserPanel)
		dresserPanel->Render();

	if (showNoKeyPanel)
		noKeyPanel->Render();
}