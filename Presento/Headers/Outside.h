#pragma once
#include "Player.h"

class Outside :public GameEntity {
private:

public:
	Outside();
	~Outside();

	void Update(Player* p);
	void Render();
};


