#pragma once
#include <iostream>

class item
{
private:
	std::string name_;
	std::string type_;
public:
	virtual void MakeStep();
};

