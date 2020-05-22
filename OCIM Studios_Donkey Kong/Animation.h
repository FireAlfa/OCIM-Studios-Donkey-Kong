#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SDL/include/SDL_rect.h"
#define MAX_FRAMES 25


//Animation Class
class Animation
{
public:
	float speed = 1.0f;
	SDL_Rect frames[MAX_FRAMES];

private:
	float current_frame = 0.0f;
	int last_frame = 0;

public:

	//Add frame to animation
	void PushBack(const SDL_Rect& rect)
	{
		frames[last_frame++] = rect;
	}

	//Restart animation
	void Reset()
	{
		current_frame = 0;
	}

	//Update the animation to change sprite
	void Update()
	{
		current_frame += speed;
		if (current_frame >= last_frame)
			current_frame = 0;
	}

	//Returns the square of the current frame
	SDL_Rect& GetCurrentFrame()
	{
		return frames[(int)current_frame];
	}
};

#endif