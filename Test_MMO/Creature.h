#pragma once
#include "Cell.h"


class Creature
{
private:
	Vector2 position;
	Vector2 hom_position;
	int hungry;
	int speed;

public:
	void Move();
	void Eat();
	void UpdatePatametres();
	void MoveToFood(int);
	int Distance(Vector2);
	int FindDirection(Vector2);
	void MoveFromHouse();
	void MoveToHouse();
	void MoveToDirection(int);
	int GetDirectionToFood();
	bool CheckFoodNear(int);
	bool CheckLife();
	bool CheckHungry();
	int GetHungry();
	Vector2 GetPosition();
	Creature();
};

