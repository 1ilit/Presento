#pragma once
#include "Tile.h"
#include "Player.h"
#include "Entity.h"
#include "GUI.h"
#include <algorithm>

class Room : public GameEntity {
private:
	enum ViewBuni {
		BLUE,
		PINK,
		PURPLE,
		YELLOW
	};
	InputMgr* input;
	Timer* timer;
	Player* p;

	//map stuff
	static const int mapHeight = 11;
	static const int mapWidth = 24;
	Tile* map[mapHeight][mapWidth];

	int m[mapHeight][mapWidth] = {
		{1,2,3,4,3,4,3,4,3,4,3,4,3,4,3,4,3,4,3,4,3,4,5,6 },
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{11,12,13,12,13,12,13,12,13,12,13,12,13,12,13,12,13,12,13,12,13,12,13,14},
		{15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15}
	};

	Vector2 screenCenter = Vector2((float)Graphics::Instance()->winWidth*0.5f, (float)Graphics::Instance()->winHeight*0.5f);

	bool screenDisabled = false;

	//closet
	ViewBuni currentBuni = BLUE;

	//for player movement
	const float gravity = 0.7f;
	bool isJumping = false;
	bool collidedTop = false;
	bool collidingBottom = false;
	bool collidingRight = false;
	bool collidingLeft = false;
	bool dirRight = true;
	float x = 0.0f;
	float y = 0.0f;
	float scrollOffset = 0.0f;
	Vector2 velocity = Vector2(4.0f, -15.0f);

	//GUI
	Panel* closetPanel;
	bool showClosetPanel=false;
	SpeechBox* doorPanel;
	bool showDoorPanel = false;

	//objects
	Entity* closet;
	Entity* door;
	Entity* bed;

	//exiting room
	bool collidingWithDoor = false;
	bool obtainedKey = false;

private:
	void HandleCloset();

public:
	Room();
	~Room();

	bool ScreenDisabled();
	bool Exited();
	void Update();
	void Render();
};