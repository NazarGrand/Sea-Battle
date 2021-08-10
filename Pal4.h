#pragma once
#include "GameMap.h";
#include"Pal.h";

class Pal4:public Pal
{
private:
	Vector l[4];

public:
	Pal4(); // конструктори
	Pal4(Vector*);
	Pal4(int**, int );
	~Pal4() {} //деструктор

	void SetPosition(Vector*);
	Vector GetValue(int);
	bool FindPal(Vector);
};

