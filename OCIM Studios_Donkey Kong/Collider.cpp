#include "Collider.h"

//Collider constructor
Collider::Collider(SDL_Rect rectangle, Type type, Module* listener) : rect(rectangle), type(type), listener(listener)
{

}

//Set the position of a collider
void Collider::SetPos(int x, int y)
{
	rect.x = x;
	rect.y = y;
}

//Check if 2 squares intersect
bool Collider::Intersects(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w &&
		rect.x + rect.w > r.x &&
		rect.y < r.y + r.h &&
		rect.h + rect.y > r.y);
}