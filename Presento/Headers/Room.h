#include "Tile.h"
#include "Player.h"
#include <algorithm>

class Room : public GameEntity {
private:
	InputMgr* input;
	Timer* timer;
	Tile* map[12][16];
	int m[12][16] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
	};
	const float speed = 350.0f;

	float yvel=-15.0f;
	const float gravity = 0.7f;
	const float groundHeight = Graphics::Instance()->winHeight - 110.0f;
	bool isJumping = false;
	const float playerSpeed = 0.2f;
	bool collidedTop = false;
	bool collidingBottom = false;
	bool collidingRight = false;
	bool collidingLeft = false;
	bool collided = false;
	float y;
	float x;

	//try
	//float fGravity = 0.35f;
	//float friction = -0.12f;
	//Vector2 acceleration = Vector2(0, fGravity);
	//bool bIsJumping = false;
	//bool bOnGround = false;
	Vector2 velocity = VEC2_ZERO;



public:
	Room();
	~Room();
	void Update(Player* p);
	void Render();
};