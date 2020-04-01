#pragma once
#include "Creature.h"
class DecisionTreeNode
{
public:
	void virtual MakeDecision(Creature & creat);
	

	DecisionTreeNode* left;
	DecisionTreeNode* rigth;
};


class DecHaveFood : public DecisionTreeNode
{
public:
	void MakeDecision(Creature& creat);
};

class DecHaveNearFood : public  DecisionTreeNode
{
public:
	void MakeDecision(Creature& creat);
};

class DecStayHome : public  DecisionTreeNode
{
public:
	void MakeDecision(Creature& creat);
};