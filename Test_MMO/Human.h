#pragma once
#include "Creature.h"
#include "DecisionTreeNode.h"

class Human : public Creature
{
public:
	DecHaveFood* root;
	Human();
	
	void MakeStep();

};
