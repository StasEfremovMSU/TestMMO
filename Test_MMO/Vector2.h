#pragma once
class Vector2
{
private:
	int x;
	int y;

public:
	Vector2();
	Vector2(int x , int y);
	int GetX();
	int GetY();
	void PutX(int x);
	void PutY(int y);
};

