#include "Tile.h"
#include "Player.h"

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
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
	};
	const float speed = 350.0f;

	float yvel;
	const float gravity = 0.7f;
	//const float groundHeight = Graphics::Instance()->winHeight - 110.0f;
	bool isJumping = false;
	const float playerSpeed = 0.2f;
	bool collidedTop = false;
	bool collidedBottom = false;

public:
	Room();
	~Room();
	void Update(Player* p);
	void Render();
};