#pragma once
#include "GameMap.h";
#include"Pal.h";

class Pal2:public Pal
{
private:
	Vector l[2];

public:
	Pal2(); // ������������
	Pal2(Vector*);
	Pal2(int**, int);
	~Pal2() {} //����������

	void SetPosition(Vector*);
	Vector GetValue(int);
	bool FindPal(Vector);
};

