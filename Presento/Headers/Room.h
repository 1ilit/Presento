#include "Tile.h"
#include "Player.h"
#include <algorithm>

class Room : public GameEntity {
private:
	InputMgr* input;
	Timer* timer;
	static const int mapHeight = 12;
	static const int mapWidth = 24;
	Tile* map[mapHeight][mapWidth];

	int m[mapHeight][mapWidth] = {
		{1,2,3,4,3,4,3,4,3,4,3,4,3,4,3,4,3,4,3,4,3,4,5,6 },
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		//{7,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,8,9,10},
		{11,12,13,12,13,12,13,12,13,12,13,12,13,12,13,12,13,12,13,12,13,12,13,14},
		{15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15}
	};

	float screenCenterX = (float)Graphics::Instance()->winWidth*0.5f;

	//for player movement
	const float gravity = 0.7f;
	bool isJumping = false;
	bool collidedTop = false;
	bool collidingBottom = false;
	bool collidingRight = false;
	bool collidingLeft = false;
	float y=0.0f;
	float x=0.0f;
	float scrollOffset = 0.0f;
	Vector2 velocity = Vector2(4.0f, -15.0f);

public:
	Room();
	~Room();
	void Update(Player* p);
	void Render();
};