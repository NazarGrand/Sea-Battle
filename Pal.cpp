#include "Pal.h"

Pal::Pal()
{
	number = 0;
}

Pal::Pal(int n)
{
	number = n;
}

int Pal::GetNumber()
{
	return number;
}

void Pal::SetNumber(int n)
{
	number = n;
}
