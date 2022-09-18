#pragma once
#include "GUI.h"
#include "World.h"
#include "Room.h"

class Play :public GameEntity {
private:
	Player* p;
	Room* r;
	

public:
	Play();
	~Play();

	void Update();
	void Render();
};
