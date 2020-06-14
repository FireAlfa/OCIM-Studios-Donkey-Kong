#ifndef __OBJECT_H__
#define __OBJECT_H_

#include "p2Point.h"
#include "Animation.h"
#include "Collider.h"




struct SDL_Texture;
struct Collider;


class Object
{
public:
	//Constructor
	Object(int x, int y);
	//Destructor
	virtual ~Object();


	// Called from inhering enemies' Udpate
	// Updates animation and collider position
	virtual void Update();

	// Called from ModuleEnemies' Update
	virtual void Draw();

	// Collision response
	// Triggers an animation and a sound fx
	virtual void OnCollision(Collider* c1, Collider* c2);



	// Sets flag for deletion and for the collider aswell
	virtual void SetToDelete();

	// Returns the enemy's collider
	const Collider* GetCollider() const;

public:

	//
	// Variables
	//

	//Position of the enemy in the map
	iPoint position;

	// The enemy's texture
	SDL_Texture* texture = nullptr;

	//Pick Up Fx
	int pickedFx = 0;

	//FLags

	// A flag for the enemy removal. Important! We do not delete objects instantly
	bool pendingToDelete = false;

protected:

	// A ptr to the current animation
	Animation* currentAnim = nullptr;

	// The enemy's collider
	Collider* objcollider = nullptr;

	// Original spawn position. Stored for movement calculations
	iPoint spawnPos;

};


#endif // !__OBJECT_H__

