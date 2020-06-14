#ifndef __BAG_H__
#define __BAG_H__

#include "Object.h"

class Bag : public Object
{
public:
	Bag(int x, int y);

	void Update() override;

private:

	Animation bagAnim;

};

#endif // !__BAG_H__
