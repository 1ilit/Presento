#pragma once
#include "GUI.h"
#include "Outside.h"
#include "Room.h"

class Play :public GameEntity {
public:
	enum World {
		ROOM,
		OUTSIDE
	};

private:
	Player* player;
	Room* room;
	Outside* outside;
	World currentWorld = ROOM;

public:
	Play();
	~Play();

	void Update();
	void Render();
};
