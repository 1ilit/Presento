#pragma once
#include <SDL.h>
#include "AnimatedTex.h"
#include "InputMgr.h"

class Button : public Texture {
protected:
	Texture* tex;
	Texture* hovering;
	bool highlight = false;
	InputMgr* input;
	int x;
	int y;

public:
	bool isSelected = false;
	bool wasClicked = false;

public:
	Button(std::string filename, int w, int h, int posx, int posy);
	Button(std::string filename, bool highlighted, int w, int h, int posx, int posy);
	~Button();

	void Update();
	void Render();

protected:
	bool Intersect();
};

class CheckBox : public Button {
private:
	Texture* check;
	Texture* title;

public:
	bool off = true;

public:
	CheckBox(std::string text, int x, int y);
	~CheckBox();

	void Update();
	void Render();

};

class Panel :public GameEntity {
private:
	Texture* panel;
	//Texture* heading;
	//Texture* icon;
	//Button* exit;
	std::map<std::string, Texture*> textures;
	std::map<std::string, Button*> buttons;
	std::map<std::string, AnimatedTex*> animations;

public:
	bool wasClosed = false;
	void SetClosed();

	Panel(Vector2 pos);
	~Panel();

	void AddButton(std::string key, std::string filename, bool b, int posx, int posy, int w, int h);
	void AddTexture(std::string key, std::string filename, float posx, float posy);
	void AddAnimation(std::string key, std::string filename, int x, int y, int w, int h, int frameC, float animationSpeed, AnimatedTex::anim_d animationDir, float posx, float posy);

	void Update();
	void Render();
};
