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
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
		{1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
	};

	float screenCenterX = (float)Graphics::Instance()->winWidth*0.5f;

	//for player movement
	const float gravity = 0.7f;
	bool isJumping = false;
	bool collidedTop = false;
	bool collidingBottom = false;
	bool collidingRight = false;
	bool collidingLeft = false;
	float y;
	float x;
	Vector2 velocity = Vector2(4.0f, -15.0f);
	Vector2 displacement = VEC2_ZERO;
	Vector2 previousPos;

public:
	Room();
	~Room();
	void Update(Player* p);
	void Render();
};