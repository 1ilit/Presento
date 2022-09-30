#include "GUI.h"

Button::Button(std::string filename, int w, int h, int posx, int posy, bool highlighted)
	:Texture(filename) {
	input = InputMgr::Instance();
	highlight = highlighted;

	Pos(Vector2((float)posx, (float)posy));

	tex = new Texture(filename, 0, 0, w, h);
	tex->Parent(this);
	tex->Pos(VEC2_ZERO);

	if (highlight) {
		hovering = new Texture(filename, w, 0, w, h);
		hovering->Parent(this);
		hovering->Pos(VEC2_ZERO);
	}

	width = w;
	height = h;
	x = posx - w*0.5f;
	y = posy - h*0.5f;
}

Button::~Button() {
	delete tex;
	tex = NULL;

	if (highlight) {
		delete hovering;
		hovering = NULL;
	}
}

bool Button::Intersect() {
	if (input->MousePos().x >= x && input->MousePos().x <= x + width &&
		input->MousePos().y >= y && input->MousePos().y <= y + height) {
	//std::cout << "here " <<  '\n';
		return true;

	}
	return false;
}

bool Button::WasClicked() {
	return wasClicked;
}

void Button::SetClicked(bool b) {
	wasClicked = b;
}

void Button::Update() {

	isSelected = Intersect();

	if (isSelected && input->MouseButtonReleased(InputMgr::left)) {
		wasClicked = true;
	}
}

void Button::Render() {
	if (highlight) {
		if (isSelected)
			hovering->Render();
		else
			tex->Render();
	}
	else {
		tex->Render();
	}
}

CheckBox::CheckBox(std::string text, int x, int y)
	:Button("check.png", true, 245 / 2, 122, x, y) {
	off = true;

	title = new Texture(text, "CourierPrime.ttf", 30, { 0, 0, 0 });
	title->Pos(Vector2(width + x + 20, y));

	check = new Texture("tick.png");
	check->Pos(Vector2(x, y));

}

CheckBox::~CheckBox() {
	delete title;
	title = NULL;

	delete check;
	check = NULL;
}

void CheckBox::Update() {
	Button::Update();
	if (wasClicked) {
		off = !off;
		wasClicked = false;
	}
}

void CheckBox::Render() {
	Button::Render();
	title->Render();
	if (!off) {
		check->Render();
	}
}

Panel::Panel(Vector2 pos) {
	Pos(pos);

	background = new Texture("panel_background.png");
	background->Scale(Vector2(8.0f, 6.0f));
	background->Parent(this);
	background->Pos(VEC2_ZERO);

	panel = new Texture("panel.png");
	panel->Parent(this);
	panel->Pos(VEC2_ZERO);	

	exit = new Button("exit.png", 30, 24, 587, 104, true);
	exit->Parent(this);

}

Panel::~Panel() {

	delete panel;
	panel = NULL;

	delete exit;
	exit = NULL;

	for (auto tex : textures) {
		if (tex.second != NULL) {
			delete tex.second;
			tex.second = NULL;
		}
	}

	textures.clear();

	for (auto p : buttons) {
		if (p.second != NULL) {
			delete p.second;
			p.second = NULL;
		}
	}

	buttons.clear();

	for (auto p : animations) {
		if (p.second != NULL) {
			delete p.second;
			p.second = NULL;
		}
	}

	animations.clear();
}

bool Panel::WasClosed() {
	return wasClosed;
}

Vector2 Panel::GetSize() {
	return panel->ScaledDimensions();
}

Texture* Panel::GetTextureByKey(std::string key) {
	return textures[key];
}

Button* Panel::GetButtonByKey(std::string key) {
	return buttons[key];
}

AnimatedTex* Panel::GetAnimationByKey(std::string key) {
	return animations[key];
}

void Panel::SetAllClicked(bool b) {
	for (auto p : buttons) {
		if (p.second != NULL)
			p.second->SetClicked(b);
	}
}

void Panel::AddButton(std::string key, std::string filename, bool b, int posx, int posy, int w, int h) {
	buttons[key] = new Button(filename, w, h, posx, posy, b);
	buttons[key]->Parent(this);
}

void Panel::AddTexture(std::string key, std::string filename, float posx, float posy) {
	textures[key] = new Texture(filename);
	textures[key]->Pos(Vector2(posx, posy));
	textures[key]->Parent(this);
}

void Panel::AddText(std::string key, std::string font, std::string text, int size, float posx, float posy, SDL_Color color) {
	textures[key] = new Texture(text, font, size, color);
	textures[key]->Pos(Vector2(posx, posy));
	textures[key]->Parent(this);
}

void Panel::AddAnimation(std::string key, std::string filename, int x, int y, int w, int h, int frameC, float animationSpeed, AnimatedTex::anim_d animationDir, float posx, float posy) {
	animations[key] = new AnimatedTex(filename, x, y, w, h, frameC, animationSpeed, animationDir);
	animations[key]->Pos(Vector2(posx, posy));
	animations[key]->Parent(this);
}

void Panel::Update() {
	exit->Update();

	for (auto tex : textures) {
		if (tex.second != NULL)
			tex.second->Render();
	}

	for (auto p : buttons) {
		if (p.second != NULL)
			p.second->Update();
	}

	//for (auto p : animations) {
	//	if (p.second != NULL)
	//		p.second->Update();
	//}

	if (exit->WasClicked()) {
		wasClosed = true;
	}
}

void Panel::SetClosed() {
	wasClosed = false;
	exit->SetClicked(false);
}

void Panel::Render() {

	background->Render();
	panel->Render();

	for (auto p : textures) {
		if (p.second != NULL)
			p.second->Render();
	}

	for (auto p : buttons) {
		if (p.second != NULL)
			p.second->Render();
	}

	//for (auto p : animations) {
	//	if (p.second != NULL)
	//		p.second->Render();
	//}

	exit->Render();
}


SpeechBox::SpeechBox(Vector2 pos, bool allRender) {
	Pos(pos);

	panel = new Texture("bottom_panel.png");
	panel->Parent(this);
	panel->Pos(VEC2_ZERO);

	renderAll = allRender;

}

SpeechBox::~SpeechBox() {
	delete panel;
	panel = NULL;
}

void SpeechBox::Update() {
	panel->Update();
	for (auto p : textures) {
		if (p.second != NULL)
			p.second->Update();
	}

	for (auto p : buttons) {
		if (p.second != NULL)
			p.second->Update();
	}
}

void SpeechBox::Render() {
	panel->Render();

	if(renderAll)
		for (auto p : textures) {
			if (p.second != NULL)
				p.second->Render();
		}

	for (auto p : buttons) {
		if (p.second != NULL)
			p.second->Render();
	}
}

PopUp::PopUp(Vector2 pos) {

	Pos(pos);

	panel=new Texture("pop_up_panel.png");
	panel->Parent(this);
	panel->Pos(VEC2_ZERO);
}

PopUp::~PopUp() {

	delete panel;
	panel = NULL;

	for (auto p : textures) {
		if (p.second != NULL)
			p.second->Update();
	}

}

void PopUp::Update() {

}

void PopUp::Render() {
	panel->Render();

	for (auto p : textures) {
		if (p.second != NULL)
			p.second->Render();
	}
}