#ifndef __COLLIDER_H__
#define __COLLIDER_H__

#include "SDL/include/SDL_Rect.h"

#define MAX_LISTENERS 5

class Module;

//Collider struct
struct Collider
{
	//
	//List of Colliders
	//
	enum Type
	{
		NONE = -1,


		WALL,
		GOUPWALL,
		RAMP_RIGHT,
		RAMP_LEFT,


		PLAYER,
		PLAYER_CENTER,
		PLAYER_FEET,

		ENEMY,

		STAIR,
		TOP_STAIR,

		STAIRBARREL,
		BUTTON,

		TOPWALL,
		LEFTWALL,
		RIGHTWALL,
		GRAVITYWALLS,

		PEACH,
		DK,



		MAX
	};

	//Methods
	Collider(SDL_Rect rectangle, Type type, Module* listener = nullptr);

	void SetPos(int x, int y);

	bool Intersects(const SDL_Rect& r) const;

	void AddListener(Module* listener);

	//Rectangle getter
	SDL_Rect GetRect();

	//Variables
	SDL_Rect rect;
	bool pendingToDelete = false;
	Type type;
	Module* listeners[MAX_LISTENERS] = { nullptr };
};


#endif // !__COLLIDER_H__