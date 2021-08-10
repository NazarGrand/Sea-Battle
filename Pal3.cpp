#include "Pal3.h"

Pal3::Pal3()
{ 
	for (int i = 0; i < 3; i++)
	{
		l[i].x = 0;
		l[i].y = 0;
	}
	number = 0;
}

Pal3::Pal3(Vector* cell)
{
	for (int i = 0; i < 3; i++)
	{
		l[i] = cell[i];
	}
	number = 0;
}

Pal3::Pal3(int** n, int m)
{
	for (int k = 0; k < m; k++)
	{
		l[k].x = n[k][0];
		l[k].y = n[k][1];
	}
	number = 0;
}

void Pal3::SetPosition(Vector* cell)
{
	for (int i = 0; i < 3; i++)
		l[i] = cell[i];
}

Vector Pal3::GetValue(int n)
{
	return l[n];
}

bool Pal3::FindPal(Vector cell)
{
	for (int i = 0; i < 3; i++)
	{
		if ((l[i].x == cell.x) && (l[i].y == cell.y))
		{
			number++;
			return true;

		}
	}
	return false;
}
