#include "AnimatedTex.h"

AnimatedTex::AnimatedTex(std::string filename, int x, int y, int w, int h, int frameC, float animationSpeed, anim_d animationDir)
	:Texture(filename, x, y, w, h) {
	timer = Timer::Instance();
	startX = x;
	startY = y;

	frameCount = frameC;
	animSpeed = animationSpeed;
	timerPerFrame = animSpeed / frameCount;
	animTimer = 0.0f;

	animDir = animationDir;
	animDone = false;
	wrapMode = loop;

}

AnimatedTex::~AnimatedTex() {

}

void AnimatedTex::RunAnimation() {
	animTimer += timer->DeltaTime();

	if (animTimer >= animSpeed) {
		if (wrapMode == loop) {
			animTimer -= animSpeed;
		}
		else {
			animDone = true;
			animTimer = animSpeed - timerPerFrame;
		}
	}
	if (animDir == horizontal) {
		clippedRect.x = startX + (int)(animTimer / timerPerFrame) * width;
	}
	else {
		clippedRect.y = startY + (int)(animTimer / timerPerFrame) * height;
	}
}

void AnimatedTex::WrapMode(wrap_mode mode) {
	wrapMode = mode;
}
void AnimatedTex::ResetAnimation() {
	animTimer = 0.0f;
	animDone = false;
}

bool AnimatedTex::IsAnimating() {
	return !animDone;
}

void AnimatedTex::Update() {
	if (!animDone) {
		RunAnimation();
	}
}
