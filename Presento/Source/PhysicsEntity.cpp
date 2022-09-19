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

void PhysicsEntity::AddCollider(Vector2 size, Vector2 localPos) {
	collider = new Collider(size);
	collider->Parent(this);
	collider->Pos(localPos);
}

void PhysicsEntity::Render() {
	collider->Render();
}