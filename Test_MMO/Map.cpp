#include "Map.h"


Map :: Map(int length, int width)
{
	for (int i = 0; i < length; i++)
	{
		vector<Cell> temp;
		temp.resize(width);
		my_map.push_back(temp);
		for (int j = 0; j < width; j++) {
			Cell x (i, j);
			my_map[i].push_back(x);
		}
	}
	this->length = length;
	this->width = width;
}

void Map::PrintMap()
{
}

bool Map::CheckFood(Vector2 x)
{
	return my_map[x.GetX()][x.GetY()].GetFood();
}

void Map::EatFood(Vector2 x)
{
	my_map[x.GetX()][x.GetY()].SetFood ( false);
}

int Map::GetLength()
{
	return length;
}

int Map::GetWidth()
{
	return width;
}