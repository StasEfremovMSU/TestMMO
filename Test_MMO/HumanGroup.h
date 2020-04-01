#pragma once
#include <vector>
#include <iostream>
#include "Human.h"

using namespace std;
class HumanGroup
{
private:

	vector <Human> Group;
public:

	HumanGroup(int x);

	void AddHumMap(vector <string> & x);

	void MakeStep();
};

