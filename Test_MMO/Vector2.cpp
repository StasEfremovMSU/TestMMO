#include "Vector2.h"

Vector2::Vector2()
{
	x = 0; y = 0;
}

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Vector2::GetX()
{
	return x;
}
int Vector2::GetY()
{
	return y;
}
void Vector2::PutX(int x)
{
	this->x = x;
}
void Vector2::PutY(int y)
{
	this->y = y;
}