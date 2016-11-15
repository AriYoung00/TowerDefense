//
// Created by collin on 11/8/16.
//

#ifndef TOWERDEFENSE_MONSTERMAN_H
#define TOWERDEFENSE_MONSTERMAN_H

#include <vector>
#include "Monsters::Monster.h"

class MonsterMan
{
public:
	MonsterMan();
	Monster makeMonster();
private:
	std::Vector<Monster> monsters;
}

#endif //TOWERDEFENSE_MONSTERMAN_H
