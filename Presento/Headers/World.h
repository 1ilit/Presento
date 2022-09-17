#pragma once
#include "Player.h"

class World :public GameEntity {
private:
	int n = 1;
	bool add = false;

public:
	World();
	~World();

	void Update(Player* p);
	void Render();
};


