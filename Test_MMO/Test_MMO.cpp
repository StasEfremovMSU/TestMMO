#include <iostream>
#include "Creature.h"
#include "Map.h"
#include "HumanGroup.h"
#include "Cell.h"
#include "Global.h"
#include <vector>
using namespace std;
#define L 10
#define D 20


Map mymap(L, D);
HumanGroup myGroup(1);

void Print()
{
	vector <string> res; // Рисуем карту
	for (int i = 0; i < L; i++)
	{
		string h = "";
		for (int j = 0; j < D; j++)
			h += ".";
		res.push_back(h);
	}
	/// отмечаем еду
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < D; j++)
			if (mymap.CheckFood(Vector2{i, j}))
				res[i].at(j) = 'f';
	}

	/// Отмечаем людей
	myGroup.AddHumMap(res);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}

	cout << endl << endl;

}

int main()
{
	
	string  d ;
	while (true)
	{
		myGroup.MakeStep();
		Print();
		cin >> d;
	}

}

