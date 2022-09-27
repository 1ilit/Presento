#include "GUI.h"

Button::Button(std::string filename, int w, int h, int posx, int posy)
	:Texture(filename) {
	input = InputMgr::Instance();

	Pos(Vector2((float)posx, (float)posy));

	tex = new Texture(filename);
	tex->Parent(this);
	tex->Pos(VEC2_ZERO);

	width = w;
	height = h;
	x = posx - w / 2;
	y = posy - h / 2;
}

Button::Button(std::string filename, bool highlighted, int w, int h, int posx, int posy)
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
	x = posx - w / 2;
	y = posy - h / 2;
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
	if (input->MousePos().x > x && input->MousePos().x < x + width &&
		input->MousePos().y<y + height && input->MousePos().y>y) {

		return true;

	}
	return false;
}

void Button::Update() {
	//std::cout << input->MousePos().x << " " << input->MousePos().y << '\n';
	isSelected = Intersect();

	if (isSelected && input->MouseButtonReleased(InputMgr::left)) {
		wasClicked = true;
		std::cout << wasClicked << '\n';
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

	exit = new Button("exit.png", true, 30, 24, 580, 100);
	exit->Parent(this);

}

Panel::~Panel() {

	delete panel;
	panel = NULL;

	delete exit;
	exit = NULL;

}

bool Panel::WasClosed() {
	return wasClosed;
}

void Panel::AddButton(std::string key, std::string filename, bool b, int posx, int posy, int w, int h) {
	buttons[key] = new Button(filename, b, w, h, posx, posy);
}

void Panel::AddTexture(std::string key, std::string filename, float posx, float posy) {
	textures[key] = new Texture(filename);
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
	if (exit->wasClicked) {
		wasClosed = true;
	}
}

void Panel::SetClosed() {
	wasClosed = false;
	exit->wasClicked = false;
}

void Panel::Render() {

	background->Render();
	panel->Render();
	exit->Render();
}

