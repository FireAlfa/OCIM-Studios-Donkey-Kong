#ifndef __ENEMY_BARREL_H__
#define __ENEMY_BARREL_H__

#include "Enemy.h"

class Enemy_Barrel : public Enemy
{
public:
	//Constructor
	Enemy_Barrel(int x, int y, int direction);

	//Enemy movment
	void Update() override;

private:
	Animation BarrelAnim;
};
	
#endif // !__ENEMY_BARREL_H__