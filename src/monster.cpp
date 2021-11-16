#include "monster.hpp"

Monster::Monster(float xPos, float yPos) : Character("content/monster1.png", xPos, yPos) {}

void Monster::Move()
{
	int dir = rand() % 4 + 1;
	if (dir == 1)
	{
		MoveDown();
	}
	else if (dir == 2)
	{
		MoveLeft();
	}
	else if (dir == 3)
	{
		MoveUp();
	}
	else
		MoveRight();
}