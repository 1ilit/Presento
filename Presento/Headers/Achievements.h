#pragma once

#include "AnimatedTex.h"
#include "GUI.h"

class Achievements : public GameEntity {
private:
	Button* back;

public:
	Achievements();
	~Achievements();

	bool WentBack();
	void SetFalse();
	void Update();
	void Render();
};