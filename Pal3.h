#pragma once
#include "GameMap.h";
#include"Pal.h";

class Pal3:public Pal
{
private:
	Vector l[3];

public:
	Pal3(); // конструктори
	Pal3(Vector*);
	Pal3(int**, int);
	~Pal3() {} //деструктор

	void SetPosition(Vector*);
	Vector GetValue(int);
	bool FindPal(Vector);
};

