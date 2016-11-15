// written by collin

#ifndef TOWERDEFENSE_MONSTER_H
#define TOWERDEFENSE_MONSTER_H

class Monster
{
public:
	Monster(double health);
	double getHealth() const;
	void hurt();
	void update();
	
private:
	double _health;
	sf::Vector2f _position;
	sf::Vector2f _heading;
}

#endif //TOWERDEFENSE_MONSTER_H
