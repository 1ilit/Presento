#include "GameEntity.h"

GameEntity::GameEntity(Vector2 pos) {
	mpos = pos;
	rotation = 0.0f;
	active = true;
	parent = NULL;
	scale = VEC2_ONE;
}

GameEntity::GameEntity(float x, float y) {
	mpos.x = x;
	mpos.y = y;

	rotation = 0;
	active = true;
	parent = NULL;
	scale = VEC2_ONE;
}

GameEntity::~GameEntity() {
	parent = NULL;
}

void GameEntity::Pos(Vector2 pos) {
	mpos = pos;
}

Vector2 GameEntity::Pos(SPACE space) {
	if (space == local || parent == NULL) {
		return mpos;
	}

	GameEntity* pparent = parent;
	Vector2 finalPos = mpos, parentScale = VEC2_ZERO;

	do {

		Vector2 parentScale = parent->Scale(local);
		finalPos = RotateVector(Vector2(finalPos.x * parentScale.x, finalPos.y * parentScale.y), pparent->Rotation(local));
		finalPos += pparent->Pos(local);

		pparent = pparent->Parent();


	} while (pparent);

	return finalPos;
}

void GameEntity::Rotation(float r) {
	rotation = r;
	if (rotation > 360.0f)
		rotation -= 360.0f;
	if (rotation < 0.0f)
		rotation += 360.0f;
}

float GameEntity::Rotation(SPACE space) {
	if (space == local || parent == NULL)
		return rotation;

	return parent->Rotation(world) + rotation;
}

void GameEntity::Scale(Vector2 scale) {
	this->scale = scale;
}

Vector2 GameEntity::Scale(SPACE space) {
	if (space == local || parent == NULL)
		return scale;

	Vector2 sscale = parent->Scale(world);
	sscale.x *= scale.x;
	sscale.y *= scale.y;

	return sscale;

}

void GameEntity::Active(bool active) {
	this->active = active;
}

bool GameEntity::Active() {
	return active;
}

void GameEntity::Parent(GameEntity* pparent) {

	if (pparent == NULL) {

		mpos = Pos(world);
		scale = Scale(world);
		rotation = Rotation(world);

	}
	else {

		if (parent != NULL)
			Parent(NULL);

		Vector2 parentScale = pparent->Scale(world);

		Vector2 normalBack(Pos(world) - pparent->Pos(world));
		mpos = RotateVector(normalBack, -pparent->Rotation(world));
		mpos.x /= parentScale.x;
		mpos.y /= parentScale.y;

		rotation = rotation - pparent->Rotation(world);

		scale = Vector2(scale.x / parentScale.x, scale.y / parentScale.y);
	}

	parent = pparent;
}


GameEntity* GameEntity::Parent() {
	return parent;
}

void GameEntity::Translate(Vector2 vec, SPACE space = local) {
	if (space == world) {
		mpos += vec;
	}
	else {
		mpos += RotateVector(vec, Rotation());
	}
}

void GameEntity::Rotate(float amount) {
	Rotation(rotation + amount);
}

void GameEntity::Update() {

}

void GameEntity::Render() {

}



