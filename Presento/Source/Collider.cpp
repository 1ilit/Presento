#include "Collider.h"

Collider::Collider(Vector2 size) {
	AddVert(0, Vector2(-0.5f * size.x, -0.5f * size.y));
	AddVert(1, Vector2(0.5f * size.x, -0.5f * size.y));
	AddVert(2, Vector2(-0.5f * size.x, 0.5f * size.y));
	AddVert(3, Vector2(0.5f * size.x, 0.5f * size.y));

	if (debug) {
		debugTex = new Texture("test.png");
		debugTex->Scale(size / 100.0f);
	}
}

Collider::~Collider() {
	for (int i = 0; i < n; i++) {
		delete verts[i];
		verts[i] = NULL;
	}
}

void Collider::AddVert(int index, Vector2 pos) {
	verts[index] = new GameEntity(pos);
	verts[index]->Parent(this);
}

bool Collider::IsColliding(Collider* other) {
	float leftA = verts[0]->Pos().x;
	float rightA = verts[1]->Pos().x;
	float topA = verts[0]->Pos().y;
	float bottomA = verts[2]->Pos().y;
	
	float leftB = other->verts[0]->Pos().x;
	float rightB = other->verts[1]->Pos().x;
	float topB = other->verts[0]->Pos().y;
	float bottomB = other->verts[2]->Pos().y;

	if (bottomA <= topB) {
		return false;
	}

	if (topA >= bottomB) {
		return false;
	}

	if (rightA <= leftB) {
		return false;
	}

	if (leftA >= rightB) {
		return false;
	}

	return true;
}

//checks if top of ``this`` collides with other
//bru its true for the side tiles smh
//add the !IsCollideringLeft or right
bool Collider::IsCollidingTop(Collider* other) {
	float topAY = verts[0]->Pos().y-14.0f; //da 14 is bc of thesprite change later
	float topBY = other->verts[0]->Pos().y;
	float bottomBY = other->verts[2]->Pos().y;

	float centerAX = (verts[0]->Pos().x+verts[1]->Pos().x)*0.5f;
	float leftBX = other->verts[2]->Pos().x;
	float rightBX = other->verts[3]->Pos().x;

	return topAY <= bottomBY && topAY>=topBY && centerAX<=rightBX && centerAX>=leftBX;
}

bool Collider::IsCollidingBottom(Collider* other) {
	float bottomAY = verts[2]->Pos().y+2;
	float topBY = other->verts[0]->Pos().y;
	float bottomBY = other->verts[2]->Pos().y;

	float centerAX = (verts[0]->Pos().x + verts[1]->Pos().x) * 0.5f;
	float leftBX = other->verts[2]->Pos().x;
	float rightBX = other->verts[3]->Pos().x;

	return bottomAY <= bottomBY && bottomAY >= topBY && centerAX <= rightBX && centerAX >= leftBX;
}

bool Collider::IsCollidingRight(Collider* other) {
	float rightAX = verts[1]->Pos().x;

	float rightBX = other->verts[1]->Pos().x;
	float leftBX = other->verts[0]->Pos().x;

	float topBY = other->verts[0]->Pos().y;
	float bottomBY = other->verts[2]->Pos().y;

	float centerAY = (verts[0]->Pos().y + verts[2]->Pos().y) * 0.5f;
	return rightAX<=rightBX && rightAX>=leftBX && centerAY>=topBY && centerAY<=bottomBY;
}

bool Collider::IsCollidingLeft(Collider* other) {
	float leftAX = verts[0]->Pos().x;

	float rightBX = other->verts[1]->Pos().x;
	float leftBX = other->verts[0]->Pos().x;

	float topBY = other->verts[0]->Pos().y;
	float bottomBY = other->verts[2]->Pos().y;

	float centerAY = (verts[0]->Pos().y + verts[2]->Pos().y) * 0.5f;
	return leftAX <= rightBX && leftAX >= leftBX && centerAY >= topBY && centerAY <= bottomBY;

}


void Collider::Render() {
	if (debug)
		debugTex->Render();
}