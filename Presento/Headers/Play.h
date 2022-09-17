#pragma once
#include "Chunk.h"
#include "GUI.h"
#include "World.h"

class Play :public GameEntity {
private:
	Player* p;
	World* w;

public:
	Play();
	~Play();

	void Update();
	void Render();
};
