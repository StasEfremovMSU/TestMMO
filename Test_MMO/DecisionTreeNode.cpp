#include "DecisionTreeNode.h"
#include "Human.h"
#include <iostream>
using namespace std;
	
void DecisionTreeNode::MakeDecision(Creature& creat)
{
}

	void DecHaveFood :: MakeDecision(Creature& creat)
	{
		if (creat.CheckHungry())
		{
			left->MakeDecision(creat);
		}
		else
			rigth->MakeDecision(creat);
	}
	
	void DecHaveNearFood::MakeDecision(Creature& creat)
	{
		creat.MoveToFood(4);
	}

	void DecStayHome::MakeDecision(Creature& creat)
	{
		creat.MoveToHouse();
	}