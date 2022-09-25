#pragma once

#include <string>
#include "GameEntity.h"
#include "Graphics.h"
#include "AssetMgr.h"

class Texture :public GameEntity {
protected:
	SDL_Texture* tex = NULL;
	Graphics* graphics = NULL;

	int width = 0;
	int height = 0;

	bool clipped;
	SDL_Rect renderRect;
	SDL_Rect clippedRect;

public:
	Texture() {};
	Texture(std::string filename);
	Texture(std::string filename, int x, int y, int w, int h);
	Texture(std::string text, std::string font, int size, SDL_Color color);
	~Texture();

	Vector2 ScaledDimensions();
	void SetClipped(int x);
	virtual void Render();
};

