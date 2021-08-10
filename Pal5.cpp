#include "Pal5.h"

Pal5::Pal5()
{  
	for (int i = 0; i < 5; i++)
	{
		l[i].x = 0;
		l[i].y = 0;
	}
	number = 0;
}

Pal5::Pal5(Vector* cell)
{ 
	for (int i = 0; i < 5; i++)
	{
		l[i] = cell[i];
	}
	number = 0;
}

Pal5::Pal5(int **n, int m)
{
	for(int k = 0; k < m; k++)
		{
			l[k].x = n[k][0];
			l[k].y = n[k][1];
		}
	number = 0;
}

void Pal5::SetPosition(Vector* cell)
{
	for (int i = 0; i < 5; i++)
		l[i] = cell[i];
}

Vector Pal5::GetValue(int n)
{
	return l[n];
}

bool Pal5::FindPal(Vector cell)
{
	for (int i = 0; i < 5; i++)
	{
		if ((l[i].x == cell.x) && (l[i].y == cell.y))
		{
			number++;
			return true;
		}
	}
	return false;
}
