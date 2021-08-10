#pragma once
#include "GameMap.h";
#include"Pal.h";

class Pal5:public Pal
{
  private:
	Vector l[5];
 
  public:
	  Pal5(); // конструктори
	  Pal5(Vector *);
	  Pal5(int** , int);
	  ~Pal5() {} //деструктор

	  void SetPosition(Vector*);
	  Vector GetValue(int);
	  bool FindPal(Vector);
};

