#include <iostream>
#include <algorithm>
#include "Creature.h"
#include "MyRand.h"
#include "Map.h"


#define MAX_HUMAN_HUNGRY 100

using namespace std;
extern Map mymap;

Creature::Creature()
{
	speed = 1;
	cout << "Constructor Creature" << endl;
	hungry = MAX_HUMAN_HUNGRY;
	hom_position = { 5,5 };
	position = { 0,0 };
}

void Creature::MoveToDirection(int x)
{
	int temp = 0;
	cout << "Move to " << x << " "<< position.GetY() <<endl;
	switch (x)
	{
	case (0):
		break;
	case(1):
		temp = position.GetX(); temp++;
		if (temp >= mymap.GetLength())
			temp = mymap.GetLength() - 1;
		position.PutX(temp);
		break;
	case(2):
		temp = position.GetX(); temp--;
		if (temp < 0) temp = 0;
		position.PutX(temp);
		break;
	case(3):
		temp = position.GetY(); temp++;
		if (temp >= mymap.GetWidth())
			temp = mymap.GetWidth() - 1;
		position.PutY(temp);
		break;
	case(4):
		temp = position.GetY(); temp--;
		if (temp < 0) temp = 0;
		position.PutY(temp);
		break;
	default:
		break;
	}
	cout << "Move to " << x << " " << position.GetY() << endl;
}

void Creature::Move()
{
	//MoveToDirection(GetDirectionToFood());
}

void Creature::Eat()
{
	if (mymap.CheckFood(position))
	{
		mymap.EatFood(position);
		hungry += 10;
	}
}
void Creature::UpdatePatametres()
{
	hungry-=2;
}

int  Creature::GetDirectionToFood()
{/// 0 нет направления
	int t = FromTo(0, 5);
	return t;
}

bool Creature::CheckLife()
{
	if (hungry > 0)
		return true;
	return false;
}

Vector2 Creature::GetPosition()
{
	return position;
}

int Creature::GetHungry()
{
	return hungry;
}

int Creature::Distance (Vector2 r)
{
	return abs (position.GetX() - r.GetX()) +  abs (position.GetY() - r.GetY());
}

int  Creature::FindDirection(Vector2 r)
{
	int dir;
	if (position.GetX() == r.GetX() && position.GetY() == r.GetY())
		return 0;
	if (position.GetX() == r.GetX())
		if (position.GetY() < r.GetY())
			return 3;
		else
			return 4;

	if (position.GetY() == r.GetY())
		if (position.GetX() < r.GetX())
			return 1;
		else
			return 2;

	int x_d = 99999; int y_d = 99999;
	x_d = position.GetX() - r.GetX();
	y_d = position.GetY() - r.GetY();
	if (abs(x_d) < abs(y_d))
	{
		if (y_d > 0)
			dir = 4;
		else
			dir = 3;
	}
	else
	{
		if (x_d > 0)
			dir = 2;
		else
			dir = 1;
	}
	
	return dir;
}

void Creature::MoveToFood(int radius)
{
	Vector2 x;
	int r = max( mymap.GetLength()+1, mymap.GetWidth() + 1);
	int min_x = max(0, position.GetX() - radius);
	int min_y = max(0, position.GetY() - radius);
	int max_x = min(mymap.GetLength(), position.GetX() + radius);
	int max_y = min(mymap.GetWidth(), position.GetY() + radius);
	bool flag = false;
	for (int i = min_x; i < max_x; ++i)
		for (int j = min_y; j < max_y; ++j)
			if (mymap.CheckFood(Vector2(i, j)) == true)
				if (Distance({ i, j }) < r)
				{
					x = { i,j };
					r = Distance({ i, j });
				}
	cout << "Near food " << x.GetX() <<"," << x.GetY() << " go to " << FindDirection(x) << endl;
	MoveToDirection(FindDirection(x));
	cout << "Move to "  << position.GetY() << endl;
}

void Creature::MoveFromHouse()
{
	int dir;
	if (FromTo(0,1) == 0)
	{
		if (position.GetX() > hom_position.GetX())
			dir = 1;
		else
			dir = 2;
		MoveToDirection(dir);
	}
	else
	{
		if (position.GetY() > hom_position.GetY())
			dir = 3;
		else
			dir = 4;
		MoveToDirection(dir);
	}
}

void Creature::MoveToHouse()
{
	MoveToDirection(FindDirection(hom_position));
}

bool Creature::CheckFoodNear(int radius)
{
	int min_x = max (0, position.GetX() - radius);
	int min_y = max (0, position.GetY() - radius);
	int max_x = min (mymap.GetLength(), position.GetX() + radius);
	int max_y = min (mymap.GetWidth(), position.GetY() + radius);
	bool flag = false;
	for (int i = min_x; i < max_x; ++i)
		for (int j = min_y; j < max_y; ++j)
		{
			mymap.CheckFood(Vector2(i, j));
			return true;
		}
	return false;
}

bool Creature::CheckHungry()
{
	if (hungry < 70)
	return true;
	return false;
}