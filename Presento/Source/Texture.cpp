#include "Texture.h"

Texture::Texture(std::string filename) {
	graphics = Graphics::Instance();

	tex = AssetMgr::Instance()->getTexture(filename);
	SDL_QueryTexture(tex, NULL, NULL, &width, &height);

	clipped = false;
	renderRect.w = width;
	renderRect.h = height;
}

Texture::Texture(std::string filename, int x, int y, int w, int h) {
	graphics = Graphics::Instance();

	tex = AssetMgr::Instance()->getTexture(filename);

	clipped = true;
	width = w;
	height = h;

	renderRect.w = width;
	renderRect.h = height;

	clippedRect.x = x;
	clippedRect.y = y;
	clippedRect.w = width;
	clippedRect.h = height;
}

Texture::Texture(std::string text, std::string font, int size, SDL_Color color) {
	graphics = Graphics::Instance();
	tex = AssetMgr::Instance()->getText(text, font, size, color);
	clipped = false;

	SDL_QueryTexture(tex, NULL, NULL, &width, &height);

	renderRect.w = width;
	renderRect.h = height;
}

Texture::~Texture() {
	tex = NULL;

	graphics = NULL;
}

void Texture::SetClipped(int x) {
	clippedRect.x += x;
}

Vector2 Texture::ScaledDimensions() {
	Vector2 scaledDim = Scale();
	scaledDim.x *= width;
	scaledDim.y *= height;

	return scaledDim;
}

void Texture::Render() {
	Vector2 pos = Pos(world);
	Vector2 scale = Scale();

	renderRect.x = (int)(pos.x - width * scale.x * 0.5f);
	renderRect.y = (int)(pos.y - height * scale.y * 0.5f);
	renderRect.w = (int)(width * scale.x);
	renderRect.h = (int)(height * scale.y);

	graphics->DrawTexture(tex, (clipped) ? &clippedRect : NULL, &renderRect, Rotation(world));
}
