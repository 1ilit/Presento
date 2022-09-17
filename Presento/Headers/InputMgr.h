#pragma once
#include <SDL.h>
#include "Texture.h"
#include "Collider.h"
#include <vector>
#include <string>

class InputMgr {
public:
	enum MOUSE_BUTTON { left = 0, right, middle, back, forward };
private:
	static InputMgr* instance;

	Uint8* prevKeyboardState;
	const Uint8* keyboardStates;
	int keyLen;

	Uint32 mPrevMouseState;
	//Holds the mouse button state of the current frame
	Uint32 mMouseState;

	//Used to retrieve the current mouse position using SDL_GetMouseState
	int mMouseXPos;
	int mMouseYPos;

public:
	static InputMgr* Instance();
	static void Release();

	bool KeyDown(SDL_Scancode sC);
	bool KeyPressed(SDL_Scancode sC);
	bool KeyReleased(SDL_Scancode sC);

	bool MouseButtonDown(MOUSE_BUTTON botton);
	bool MouseButtonPressed(MOUSE_BUTTON button);
	bool MouseButtonReleased(MOUSE_BUTTON button);
	Vector2 MousePos();

	void Update();
	void UpdatePrevInput();

private:
	InputMgr();
	~InputMgr();

};

class Mouse {
public:
	SDL_Texture* tex;
	SDL_Rect rect;
	SDL_Rect point;

public:
	Mouse();
	~Mouse();
	void Update();
	void Render();
};
