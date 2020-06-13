#ifndef __ENEMY_CEMENT_H__
#define __ENEMY_CEMENT_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Cement : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Cement(int x, int y, int direction);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

private:
	SDL_Texture* Texture = nullptr;

	// The path that will define the position in the world
	Path path;

	// Enemy animations
	Animation Cement, back;
};

#endif // __ENEMY_DONKEYKONG_H__