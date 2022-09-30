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

AnimEntity::AnimEntity(std::string filename, int x, int y, int w, int h, int frameC, float animationSpeed, AnimatedTex::anim_d animationDir, AnimatedTex::wrap_mode mode) :Entity(filename) {
	tex = new AnimatedTex(filename, x, y, w, h, frameC, animationSpeed, animationDir);
	tex->WrapMode(mode);
	tex->Parent(this);

	AddCollider(tex->ScaledDimensions());
}

AnimEntity::~AnimEntity() {
	delete tex;
	tex = NULL;
}

bool AnimEntity::AnimDone() {
	return !tex->IsAnimating();
}

void AnimEntity::Update(){
	tex->Update();
}

void AnimEntity::Render() {
	tex->Render();
}

