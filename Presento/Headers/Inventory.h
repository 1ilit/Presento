#pragma once
#include "Texture.h";

class Inventory :public GameEntity {
public:
	enum Item {
		EMPTY=11,
		APPLE=12,
		BOOK=13,
		FISH=14,
		HAT=15,
		LADDER=17,
		PENCIL=18
	};

private:
	Item currentItem = EMPTY;
	Texture* emptyI;
	Texture* appleI;
	Texture* bookI;
	Texture* fishI;
	Texture* hatI;
	Texture* ladderI;
	Texture* pencilI;

public:
	Inventory();
	~Inventory();

	Item GetCurrentItem();
	void SetItem(Item item);
	void Update();
	void Render();
};