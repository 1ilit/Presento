#include "Graphics.h"

Graphics* Graphics::instance = NULL;

bool Graphics::isInit = false;

Graphics::Graphics() {
	isInit = Init();
}

Graphics::~Graphics() {
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_Quit();
	TTF_Quit();
	IMG_Quit();
}

Graphics* Graphics::Instance() {
	if (!instance)
		instance = new Graphics();

	return instance;
}

void Graphics::Release() {
	delete instance;
	instance = NULL;

	isInit = false;
}

bool Graphics::Initialized() {
	return isInit;
}

bool Graphics::Init() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		std::cout << "init error: " << SDL_GetError() << '\n';
		return false;
	}

	window = SDL_CreateWindow(winTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, winWidth, winHeight, SDL_WINDOW_SHOWN);

	if (!window) {
		std::cout << "window init error: " << SDL_GetError() << '\n';
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!renderer) {
		std::cout << "renderer init error: " << SDL_GetError() << '\n';
		return false;
	}

	SDL_SetRenderDrawColor(renderer, 63, 34, 124, 255); //63

	int flag = IMG_INIT_PNG;

	if (!(IMG_Init(flag) & flag)) {
		std::cout << "img init error: " << SDL_GetError() << '\n';
		return false;
	}

	if (TTF_Init() == -1) {
		std::cout << "ttf init error: " << SDL_GetError() << '\n';
		return false;
	}

	backBuffer = SDL_GetWindowSurface(window);

	return true;
}

SDL_Renderer* Graphics::getRenderer() {
	return renderer;
}

SDL_Texture* Graphics::LoadTexture(std::string path) {
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (!surface) {
		std::cout << "img load path error: " << IMG_GetError() << " at: " << path << '\n';
		return NULL;
	}

	SDL_Texture* tex = IMG_LoadTexture(renderer, path.c_str());
	if (!tex) {
		std::cout << "tex creation error: " << SDL_GetError() << '\n';
		return NULL;
	}

	SDL_FreeSurface(surface);
	return tex;
}

SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color) {
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (!surface) {
		std::cout << "text render error: " << TTF_GetError() << '\n';
		return NULL;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
	if (!tex) {
		std::cout << "text texture error: " << SDL_GetError() << '\n';
		return NULL;
	}

	SDL_FreeSurface(surface);
	return tex;
}

void Graphics::DrawTexture(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend, float angle, SDL_RendererFlip flip) {
	SDL_RenderCopyEx(renderer, tex, clip, rend, angle, NULL, flip);
}


void Graphics::DrawLine(float startX, float startY, float endX, float endY) {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, startX, startY, endX, endY);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}


void Graphics::ClearBackBuffer() {
	SDL_RenderClear(renderer);
}

void Graphics::Render() {
	SDL_RenderPresent(renderer);
}


