#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Graphics {
public:
	static const int winWidth = 768;
	static const int winHeight = 528;
	const char* winTitle = "Dream Chaser";

private:
	static Graphics* instance;
	static bool isInit;

	SDL_Window* window;
	SDL_Surface* backBuffer;
	SDL_Renderer* renderer;

public:
	static Graphics* Instance();
	static void Release();
	bool Initialized();
	SDL_Renderer* getRenderer();

	SDL_Texture* LoadTexture(std::string path);
	SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);

	void ClearBackBuffer();
	void DrawTexture(SDL_Texture* tex, SDL_Rect* clip = NULL, SDL_Rect* rend = NULL, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawLine(float startX, float startY, float endX, float endY);

	void Render();

private:
	Graphics();
	~Graphics();
	bool Init();

};

