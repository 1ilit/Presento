#pragma once
#include "Texture.h"

class Collider : public GameEntity {
private:
	static const bool debug = true;
	static const int n = 4;
	GameEntity* verts[n];
	Texture* debugTex;

private:
	void AddVert(int index, Vector2 pos);

public:
	Collider(Vector2 size);
	~Collider();

	bool IsColliding(Collider* other);
	bool IsCollidingTop(Collider* other);
	bool IsCollidingBottom(Collider* other);
	bool IsCollidingLeft(Collider* other);
	bool IsCollidingRight(Collider* other);

	void Render();
};
