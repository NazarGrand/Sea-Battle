#include "Pal2.h"

Pal2::Pal2()
{
	for (int i = 0; i < 2; i++)
	{
		l[i].x = 0;
		l[i].y = 0;
	}
	number = 0;
}

Pal2::Pal2(Vector* cell)
{
	for (int i = 0; i < 2; i++)
	{
		l[i] = cell[i];
	}
	number = 0;
}

Pal2::Pal2(int** n, int m)
{
	for (int k = 0; k < m; k++)
	{
		l[k].x = n[k][0];
		l[k].y = n[k][1];
	}
	number = 0;
}

void Pal2::SetPosition(Vector* cell)
{
	for (int i = 0; i < 2; i++)
		l[i] = cell[i];
}


Vector Pal2::GetValue(int n)
{
	return l[n];
}


bool Pal2::FindPal(Vector cell)
{
	for (int i = 0; i < 2; i++)
	{
		if ((l[i].x == cell.x) && (l[i].y == cell.y))
		{
			number++;
			return true;

		}
	}
	return false;
}


