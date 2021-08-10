#pragma once
#include "GameMap.h";
#include"Pal.h";

class Pal2:public Pal
{
private:
	Vector l[2];

public:
	Pal2(); // конструктори
	Pal2(Vector*);
	Pal2(int**, int);
	~Pal2() {} //деструктор

	void SetPosition(Vector*);
	Vector GetValue(int);
	bool FindPal(Vector);
};

