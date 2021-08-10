#include "Pal1.h"

Pal1::Pal1()
{
	l.x = 0;
	l.y = 0;
	number = 0;
}

Pal1::Pal1(Vector cell)
{
	l = cell;
	number = 0;
}

Pal1::Pal1(int n, int m)
{
	l.x = n;
	l.y = m;
	number = 0;
}

void Pal1::SetPosition(Vector cell)
{
	l = cell;
}


Vector Pal1::GetValue()
{
	return l;
}

bool Pal1::FindPal(Vector cell)
{
		if ((l.x == cell.x) && (l.y == cell.y))
		{
			number++;
			return true;

		}
	return false;
}

