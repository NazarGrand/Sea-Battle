#pragma once
#include "GameMap.h";

class Pal
{
 protected:
	int number;

public:
	Pal();
	Pal(int);
	~Pal() {}
	int GetNumber();
	void SetNumber(int);
};

