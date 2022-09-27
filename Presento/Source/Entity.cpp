#include "Entity.h"

Entity::Entity(std::string filename) {
	tex = new Texture(filename);
	tex->Parent(this);

	AddCollider(tex->ScaledDimensions());
}

Entity::~Entity() {
	delete tex;
	tex = NULL;
}

void Entity::Update() {
	tex->Update();
}

void Entity::Render() {
	tex->Render();
}