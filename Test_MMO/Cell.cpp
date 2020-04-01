#include "Cell.h"
#include <cstdlib>

void Cell::RandomFoodGenerate()
{
	food = rand()%2;
}

Cell::Cell()
{
	food = false;
	coordinate.PutX(0);
	coordinate.PutY(0);
	RandomFoodGenerate();
}

bool Cell::GetFood()
{
	return food;
}

void Cell::SetFood(bool x)
{
	food = x;
}
Cell::Cell(int x , int y)
{
	coordinate.PutX (x);
	coordinate.PutY (y);
	RandomFoodGenerate();
}