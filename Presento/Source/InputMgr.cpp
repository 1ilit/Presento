#include "InputMgr.h"

InputMgr* InputMgr::instance = NULL;

InputMgr* InputMgr::Instance() {
	if (instance == NULL)
		instance = new InputMgr();

	return instance;
}

void InputMgr::Release() {
	delete instance;
	instance = NULL;
}

InputMgr::InputMgr() {
	keyboardStates = SDL_GetKeyboardState(&keyLen);
	prevKeyboardState = new Uint8[keyLen];
	memcpy(prevKeyboardState, keyboardStates, keyLen);
}

InputMgr::~InputMgr() {
	delete prevKeyboardState;
	prevKeyboardState = NULL;
}

bool InputMgr::KeyDown(SDL_Scancode sC) {
	return keyboardStates[sC];
}

bool InputMgr::KeyPressed(SDL_Scancode sC) {
	return !prevKeyboardState[sC] && keyboardStates[sC];
}

bool InputMgr::KeyReleased(SDL_Scancode sC) {
	return prevKeyboardState[sC] && !keyboardStates[sC];
}

Vector2 InputMgr::MousePos() {
	return Vector2((float)mMouseXPos, (float)mMouseYPos);
}


bool InputMgr::MouseButtonDown(MOUSE_BUTTON button) {

	//mask to be using for bit wise operations
	Uint32 mask = 0;

	switch (button) {

	case left:

		mask = SDL_BUTTON_LMASK;
		break;

	case right:

		mask = SDL_BUTTON_RMASK;
		break;

	case middle:

		mask = SDL_BUTTON_MMASK;
		break;

	case back:

		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:

		mask = SDL_BUTTON_X2MASK;
		break;
	}

	//return true if the mask exists in the current mouse state
	return ((mMouseState & mask) != 0);
}

bool InputMgr::MouseButtonPressed(MOUSE_BUTTON button) {

	//mask to be using for bit wise operations
	Uint32 mask = 0;

	switch (button) {

	case left:

		mask = SDL_BUTTON_LMASK;
		break;

	case right:

		mask = SDL_BUTTON_RMASK;
		break;

	case middle:

		mask = SDL_BUTTON_MMASK;
		break;

	case back:

		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:

		mask = SDL_BUTTON_X2MASK;
		break;
	}

	//return true if the mask does not exist in the previous mouse state, but exists in the current one
	return ((mPrevMouseState & mask) == 0) && ((mMouseState & mask) != 0);
}

bool InputMgr::MouseButtonReleased(MOUSE_BUTTON button) {

	Uint32 mask = 0;

	switch (button) {

	case left:

		mask = SDL_BUTTON_LMASK;
		break;

	case right:

		mask = SDL_BUTTON_RMASK;
		break;

	case middle:

		mask = SDL_BUTTON_MMASK;
		break;

	case back:

		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:

		mask = SDL_BUTTON_X2MASK;
		break;
	}

	//return true if the mask exists in the previous mouse state, but does not exist in the current one
	return (mPrevMouseState & mask) && !(mMouseState & mask);
}

void InputMgr::Update() {

	//Updating the mouse state to get the key states of the current frame
	mMouseState = SDL_GetMouseState(&mMouseXPos, &mMouseYPos);
}

void InputMgr::UpdatePrevInput() {

	//Copying the keyboard state into the previous keyboard state array at the end of the frame
	memcpy(prevKeyboardState, keyboardStates, keyLen);
	//Setting the previous mouse state as the current mouse state at the end of the frame
	mPrevMouseState = mMouseState;
}

Mouse::Mouse() {
	tex = AssetMgr::Instance()->getTexture("cursor.png");
	rect.w = 35;
	rect.h = 40;
	point.w = 1;
	point.h = 1;
	SDL_ShowCursor(false);
}

Mouse::~Mouse() {

}

void Mouse::Update() {
	SDL_GetMouseState(&rect.x, &rect.y);
	point.x = rect.y;
	point.y = rect.y;
}

void Mouse::Render() {
	SDL_RenderCopy(Graphics::Instance()->getRenderer(), tex, NULL, &rect);
}