#include "PhysicsEntity.h"
#include "Collider.h"

PhysicsEntity::PhysicsEntity() {

}

PhysicsEntity::~PhysicsEntity() {
	delete collider;
	collider = NULL;
}

bool PhysicsEntity::CheckCollision(PhysicsEntity* other) {
	return collider->IsColliding(other->collider);
}

bool PhysicsEntity::CheckTopCollision(PhysicsEntity* other) {
	return collider->IsCollidingTop(other->collider);
}

bool PhysicsEntity::CheckBottomCollision(PhysicsEntity* other) {
	return collider->IsCollidingBottom(other->collider);
}

bool PhysicsEntity::CheckLeftCollision(PhysicsEntity* other) {
	return collider->IsCollidingLeft(other->collider);
}

bool PhysicsEntity::CheckRightCollision(PhysicsEntity* other) {
	return collider->IsCollidingRight(other->collider);
}

void PhysicsEntity::AddCollider(Vector2 size, Vector2 localPos) {
	collider = new Collider(size, localPos);
	collider->Parent(this);
	collider->Pos(localPos);
}

void PhysicsEntity::Render() {
	collider->Render();
}