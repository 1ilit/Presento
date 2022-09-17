#pragma once

#include "MathHelper.h"
#include <vector>

class GameEntity {

public:

	enum SPACE {
		local = 0,
		world = 1
	};

private:

	Vector2 mpos;
	float rotation;
	Vector2 scale;
	bool active;
	GameEntity* parent;

public:
	GameEntity(Vector2 pos);
	GameEntity(float x = 0.0f, float y = 0.0f);
	~GameEntity();

	void Pos(Vector2 pos);
	Vector2 Pos(SPACE space = world);

	void Rotation(float rotation);
	float Rotation(SPACE space = world);

	void Active(bool p_active);
	bool Active();

	void Scale(Vector2 scale);
	Vector2 Scale(SPACE space = world);

	void Parent(GameEntity* parent);
	GameEntity* Parent();

	void Translate(Vector2 vec, SPACE space);
	void Rotate(float amount);

	virtual void Update();
	virtual void Render();

};