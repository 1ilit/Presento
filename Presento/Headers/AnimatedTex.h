#pragma once

#include "Timer.h"
#include "Texture.h"

class AnimatedTex :public Texture {
public:
	enum wrap_mode {
		once = 0,
		loop = 1
	};

	enum anim_d {
		horizontal = 0,
		vertical = 1
	};

protected:
	Timer* timer;
	int startX;
	int startY;

	float animTimer;
	float animSpeed;
	float timerPerFrame;

	int frameCount;
	wrap_mode wrapMode;
	anim_d animDir;

	bool animDone;

protected:
	virtual void RunAnimation();

public:
	AnimatedTex(std::string filename, int x, int y, int w, int h, int frameC, float animationSpeed, anim_d animationDir);
	~AnimatedTex();

	void WrapMode(wrap_mode mode);
	virtual void ResetAnimation();
	bool IsAnimating();
	void Update();
};
