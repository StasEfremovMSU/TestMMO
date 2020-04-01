#include "HumanGroup.h"

void HumanGroup::MakeStep()
{
	for (int i = 0; i < Group.size(); i++)
	{
		Group[i].MakeStep();
	}

	/// Удаляем голодных
	for (int i = 0; i < Group.size(); i++)
	{
		if (Group[i].CheckLife() == false)
		{
			Group.erase(Group.begin() + i);
			i--;
		}
	}
}

HumanGroup::HumanGroup(int c)
{
	for (int i = 0; i < c; i++)
	{
		Human temp;
		Group.push_back(temp);
	}
}

void HumanGroup::AddHumMap(vector <string>& x)
{
	for (int i = 0; i < Group.size(); i++)
	{
		int g = Group[i].GetPosition().GetX();
		int h = Group[i].GetPosition().GetY();
		if (x[g].at(h) != 'h')
			x[g].at(h) = 'h';
		else
			x[g].at(h) = 'G';
	}
}