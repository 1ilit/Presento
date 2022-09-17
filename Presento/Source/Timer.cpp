#include "Timer.h"

Timer* Timer::instance = NULL;

Timer* Timer::Instance() {
	if (instance == NULL) {
		instance = new Timer();
	}
	return instance;
}

void Timer::Release() {
	delete instance;
	instance = NULL;
}

Timer::Timer() {
	Reset();
	elapsedTicks = 0;
	deltaTime = 0.0f;
	timeScale = 1.0f;
}

Timer::~Timer() {

}

void Timer::Reset() {
	startTicks = SDL_GetTicks();
}

float Timer::DeltaTime() {
	return deltaTime;
}

void Timer::TimeScale(float t) {
	timeScale = t;
}

float Timer::TimeScale() {
	return timeScale;
}

void Timer::Update() {
	elapsedTicks = SDL_GetTicks() - startTicks;
	deltaTime = elapsedTicks * 0.001f;
}