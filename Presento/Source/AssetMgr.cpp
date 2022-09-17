#include "AssetMgr.h"

AssetMgr* AssetMgr::instance = NULL;

AssetMgr* AssetMgr::Instance() {
	if (instance == NULL)
		instance = new AssetMgr();

	return instance;
}

void AssetMgr::Release() {
	delete instance;
	instance = NULL;
}

AssetMgr::AssetMgr() {

}

AssetMgr::~AssetMgr() {
	for (auto tex : textures) {
		if (tex.second != NULL)
			SDL_DestroyTexture(tex.second);
	}

	textures.clear();

	for (auto text : texts) {
		if (text.second != NULL)
			SDL_DestroyTexture(text.second);
	}

	texts.clear();

	for (auto font : fonts) {
		if (font.second != NULL)
			TTF_CloseFont(font.second);
	}

	fonts.clear();
}

SDL_Texture* AssetMgr::getTexture(std::string filename) {
	std::string s = SDL_GetBasePath();
	s.append("Assets/" + filename);

	if (textures[s] == NULL) {
		textures[s] = Graphics::Instance()->LoadTexture(s);
	}
	return textures[s];
}

TTF_Font* AssetMgr::getFont(std::string filename, int size) {

	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	std::string key = fullPath + (char)size;

	if (fonts[key] == NULL) {
		fonts[key] = TTF_OpenFont(fullPath.c_str(), size);

		if (fonts[key] == nullptr)
			std::cout << "font loading error: font " << filename.c_str() << "error: " << TTF_GetError() << std::endl;

	}
	return fonts[key];

}

SDL_Texture* AssetMgr::getText(std::string text, std::string filename, int size, SDL_Color color) {
	TTF_Font* font = getFont(filename, size);

	std::string key = text + filename + (char)size + (char)color.r + (char)color.b + (char)color.g;

	if (texts[key] == nullptr) {
		texts[key] = Graphics::Instance()->CreateTextTexture(font, text, color);
	}

	return texts[key];
}


