#pragma once
#include "GameMap.h";
#include"Pal.h";

class Pal5:public Pal
{
  private:
	Vector l[5];
 
  public:
	  Pal5(); // ������������
	  Pal5(Vector *);
	  Pal5(int** , int);
	  ~Pal5() {} //����������

	  void SetPosition(Vector*);
	  Vector GetValue(int);
	  bool FindPal(Vector);
};

