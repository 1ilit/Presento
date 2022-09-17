#pragma once

#include "Graphics.h"
#include <map>

class AssetMgr {
private:
	static AssetMgr* instance;
	std::map<std::string, SDL_Texture*> textures;
	std::map<std::string, SDL_Texture*> texts;
	std::map<std::string, TTF_Font*> fonts;

public:
	static AssetMgr* Instance();
	static void Release();

	SDL_Texture* getTexture(std::string filename);
	SDL_Texture* getText(std::string text, std::string filename, int size, SDL_Color color);

private:
	AssetMgr();
	~AssetMgr();

	TTF_Font* getFont(std::string filename, int size);
};