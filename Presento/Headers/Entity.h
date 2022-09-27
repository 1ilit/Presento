#pragma once
#include "PhysicsEntity.h"

class Entity : public PhysicsEntity {
private:
	Texture* tex;

public:
	Entity(std::string fileName);
	~Entity();

	void Render();
	void Update();
};