#pragma once
#include "AnimatedTex.h"
#include "PhysicsEntity.h"

class Entity : public PhysicsEntity {
private:
	Texture* tex;

public:

	Entity(std::string fileName);
	~Entity();

	virtual void Render();
	virtual void Update();
};

class AnimEntity : public Entity {
private:
	AnimatedTex* tex;

public:
	AnimEntity(std::string filename, int x, int y, int w, int h, int frameC, float animationSpeed, AnimatedTex::anim_d animationDir, AnimatedTex::wrap_mode mode);
	~AnimEntity();

	bool AnimDone();
	void Render() override;
	void Update() override;
};