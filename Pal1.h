#pragma once
#include "GameMap.h";
#include"Pal.h";

class Pal1:public Pal
{
private:
	Vector l;

public:
	Pal1(); // ������������
	Pal1(Vector);
	Pal1(int, int);
	~Pal1() {} //����������

	void SetPosition(Vector);
	Vector GetValue();
	bool FindPal(Vector);
};

