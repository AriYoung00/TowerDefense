#ifndef STATE_MANAGER_H_INCLUDED
#define STATE_MANAGER_H_INCLUDED

class StateManager {
public:
	StateManager();
	void removeLife();
	void addScore(int number);
	void addCoins(int number);
	bool removeCoins(int number);
	int getLives();
	int getScore();
	int getCoins();
private:
	int _lives;
	int _score;
	int _coins;
};

#endif
