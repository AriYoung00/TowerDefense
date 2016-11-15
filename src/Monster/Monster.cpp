
#include "Monsters/Monster.h"

namespace Monsters
{
	Monster::Monster(double health) : _health{health}
	{}
	
	double Monster::getHealth()
	{
		return _health;
	}
}
