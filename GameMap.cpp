#include "GameMap.h"


GameMap::GameMap()
{
	size.x = 0;
	size.y = 0;
}

GameMap::GameMap(Vector _size)
{
	size = _size;

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++)
		map[i] = new int[size.y];

	//обнуляємо
	for (int i = 0; i < size.x; i++)
		for (int j = 0; j < size.y; j++)
			map[i][j] = 0;
}

GameMap::GameMap(int n, int m)
{
	size.x = n;
	size.y = m;

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++)
		map[i] = new int[size.y];

	//обнуляємо
	for (int i = 0; i < size.x; i++)
		for (int j = 0; j < size.y; j++)
			map[i][j] = 0;
}

GameMap::~GameMap()
{
	for (int i = 0; i < size.x; i++)
		delete[] map[i];

	delete[] map;
}

bool GameMap::SetPosition(Vector cell, int c)
{
	if (IsEmpty(cell))
	{
		map[cell.x][cell.y] = c;
		return true;
	}
	else
		return false;
}

bool GameMap::SetPositionForGame(Vector cell, int c)
{
	if ( (IsEmpty(cell)) || (map[cell.x][cell.y] == 1))
	{
		map[cell.x][cell.y] = c;
		return true;
	}
	else
		return false;
}

bool GameMap::IsEmpty(Vector cell)
{
	if (map[cell.x][cell.y] == 0)
		return true;
	else
		return false;
}

bool GameMap::IsEmpty(int n, int m)
{
	if (map[n][m] == 0)
		return true;
	else
		return false;
}

void GameMap::SetMap(Vector _size)
{
	size = _size;

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++)
		map[i] = new int[size.y];

	//обнуляємо
	for (int i = 0; i < size.x; i++)
		for (int j = 0; j < size.y; j++)
			map[i][j] = 0;
}

void GameMap::SetMap(int n, int m)
{
	size.x = n;
	size.y = m;

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++)
		map[i] = new int[size.y];

	//обнуляємо
	for (int i = 0; i < size.x; i++)
		for (int j = 0; j < size.y; j++)
			map[i][j] = 0;
}

int GameMap::GetValue(Vector cell)
{
	return map[cell.x][cell.y];
}

int GameMap::GetValue(int n, int m)
{
	return map[n][m];
}


int GameMap::CheckingWin()
{
	int number = 0;
	for (int i = 0; i < size.x; i++)
		for (int j = 0; j < size.y; j++)
			if (map[i][j] == 3)
				number++;
	if (number == 35)
		return 1; //переміг
	else
		return 0; //ще ні
}

bool GameMap::CheckForShips(Vector cell, int k)
{   
	int number = 0, t = 0;
	Vector v[2];
	
	for(int i = 0; i < size.x; i++)
		for (int j = 0; j < size.y; j++)
		{
			if (map[i][j] == k)
			{
				number++;
			        
				if (t < 2)
				{
					v[t].x = i;
					v[t].y = j;
					t++;
				}
			}
		}
	 
	if (number == 0)
	{
		if ((cell.x == 0) && (cell.y == 0))
		{
			if ((map[cell.x][cell.y + 1] == 0) && (map[cell.x + 1][cell.y] == 0) && (map[cell.x + 1][cell.y + 1] == 0))
				return true;
			else
				return false;
		}

		if ((cell.x == 0) && (cell.y == size.y - 1))
		{
			if ((map[cell.x][cell.y - 1] == 0) && (map[cell.x + 1][cell.y] == 0) && (map[cell.x + 1][cell.y - 1] == 0))
				return true;
			else
				return false;
		}

		if ((cell.x == size.x - 1) && (cell.y == size.y - 1))
		{
			if ((map[cell.x - 1][cell.y] == 0) && (map[cell.x][cell.y - 1] == 0) && (map[cell.x - 1][cell.y - 1] == 0))
				return true;
			else
				return false;
		}

		if ((cell.x == size.x - 1) && (cell.y == 0))
		{
			if ((map[cell.x - 1][cell.y] == 0) && (map[cell.x][cell.y + 1] == 0) && (map[cell.x - 1][cell.y + 1] == 0))
				return true;
			else
				return false;
		}

		if ((cell.x != 0) && (cell.y == 0))
		{
			if ((map[cell.x - 1][cell.y] == 0) && (map[cell.x + 1][cell.y] == 0) && (map[cell.x][cell.y + 1] == 0) && (map[cell.x - 1][cell.y + 1] == 0) 
				&& (map[cell.x + 1][cell.y + 1] == 0))
				return true;
			else
				return false;
		}

		if ((cell.x == 0) && (cell.y != 0))
		{
			if ((map[cell.x][cell.y - 1] == 0) && (map[cell.x][cell.y + 1] == 0) && (map[cell.x + 1][cell.y] == 0) && (map[cell.x + 1][cell.y - 1] == 0) 
				&& (map[cell.x + 1][cell.y + 1] == 0))
				return true;
			else
				return false;
		}

		if ((cell.x != 0) && (cell.y == size.y - 1))
		{
			if ((map[cell.x - 1][cell.y] == 0) && (map[cell.x + 1][cell.y] == 0) && (map[cell.x][cell.y - 1] == 0) && (map[cell.x - 1][cell.y - 1] == 0)
				&& (map[cell.x + 1][cell.y - 1] == 0))
				return true;
			else
				return false;
		}

		if ((cell.x == size.x - 1) && (cell.y != 0))
		{
			if ((map[cell.x][cell.y - 1] == 0) && (map[cell.x][cell.y + 1] == 0) && (map[cell.x - 1][cell.y] == 0) && (map[cell.x - 1][cell.y - 1] == 0)
				&& (map[cell.x - 1][cell.y + 1] == 0))
				return true;
			else
				return false;
		}

		if ((cell.x != 0) && (cell.y != 0))
		{
			if ((map[cell.x][cell.y - 1] == 0) && (map[cell.x][cell.y + 1] == 0) && (map[cell.x - 1][cell.y] == 0) 
				&& (map[cell.x + 1][cell.y] == 0) && (map[cell.x - 1][cell.y - 1] == 0) && (map[cell.x - 1][cell.y + 1] == 0)
				&& (map[cell.x + 1][cell.y - 1] == 0) && (map[cell.x + 1][cell.y + 1] == 0))
				return true;
			else
				return false;
		}

	}

	if (number > 1)
	{
		if ( (v[0].x == v[1].x) && (v[0].x != cell.x))
			return false;
		if ((v[0].y == v[1].y) && (v[0].y != cell.y))
			return false;
	}

	if ((cell.x == 0) && (cell.y == 0))
	{  
		if (((map[cell.x][cell.y + 1] == 0) || (map[cell.x][cell.y + 1] == k)) &&
			((map[cell.x + 1][cell.y] == 0) || (map[cell.x + 1][cell.y] == k)) &&
			((map[cell.x][cell.y + 1] == k) || (map[cell.x + 1][cell.y] == k)) && 
			(map[cell.x + 1][cell.y + 1] == 0))
			return true;
		else
			return false;
	}

	if ((cell.x == 0) && (cell.y == size.y - 1))
	{    
		if (((map[cell.x][cell.y - 1] == 0) || (map[cell.x][cell.y - 1] == k)) &&
			((map[cell.x + 1][cell.y] == 0) || (map[cell.x + 1][cell.y] == k)) &&
			((map[cell.x][cell.y - 1] == k) || (map[cell.x + 1][cell.y] == k)) && (map[cell.x + 1][cell.y - 1] == 0))
			return true;
		else
			return false;
	}

	if ((cell.x == size.x - 1) && (cell.y == size.y - 1))
	{
		if (((map[cell.x - 1][cell.y] == 0) || (map[cell.x - 1][cell.y] == k)) &&
			((map[cell.x][cell.y - 1] == 0) || (map[cell.x][cell.y - 1] == k)) &&
			((map[cell.x - 1][cell.y] == k) || (map[cell.x][cell.y - 1] == k)) && (map[cell.x - 1][cell.y - 1] == 0))
			return true;
		else
			return false;
	}

	if ((cell.x == size.x - 1) && (cell.y == 0))
	{
		if (((map[cell.x - 1][cell.y] == 0) || (map[cell.x - 1][cell.y] == k)) &&
			((map[cell.x][cell.y + 1] == 0) || (map[cell.x][cell.y + 1] == k)) &&
			((map[cell.x - 1][cell.y] == k) || (map[cell.x][cell.y + 1] == k)) && (map[cell.x - 1][cell.y + 1] == 0))
			return true;
		else
			return false;
	}

	if ((cell.x != 0) && (cell.y == 0))
	{
		if (((map[cell.x - 1][cell.y] == 0) || (map[cell.x - 1][cell.y] == k)) &&
			((map[cell.x + 1][cell.y] == 0) || (map[cell.x + 1][cell.y] == k)) &&
			((map[cell.x][cell.y + 1] == 0) || (map[cell.x][cell.y + 1] == k)) &&
			((map[cell.x - 1][cell.y] == k) || (map[cell.x + 1][cell.y] == k) || (map[cell.x][cell.y + 1] == k))
			&& (map[cell.x - 1][cell.y + 1] == 0)
			&& (map[cell.x + 1][cell.y + 1] == 0))
			return true;
		else
			return false;
	}

	if ((cell.x == 0) && (cell.y != 0))
	{
		if (((map[cell.x][cell.y - 1] == 0) || (map[cell.x][cell.y - 1] == k)) &&
			((map[cell.x][cell.y + 1] == 0) || (map[cell.x][cell.y + 1] == k)) &&
			((map[cell.x + 1][cell.y] == 0) || (map[cell.x + 1][cell.y] == k)) &&
			((map[cell.x][cell.y - 1] == k) || (map[cell.x][cell.y + 1] == k) || (map[cell.x + 1][cell.y] == k))
			&& (map[cell.x + 1][cell.y - 1] == 0)
			&& (map[cell.x + 1][cell.y + 1] == 0))
			return true;
		else
			return false;
	}

	if ((cell.x != 0) && (cell.y == size.y - 1))
	{
		if (((map[cell.x - 1][cell.y] == 0) || (map[cell.x - 1][cell.y] == k)) &&
			((map[cell.x + 1][cell.y] == 0) || (map[cell.x + 1][cell.y] == k)) &&
			((map[cell.x][cell.y - 1] == 0) || (map[cell.x][cell.y - 1] == k)) &&
			((map[cell.x - 1][cell.y] == k) || (map[cell.x + 1][cell.y] == k) || (map[cell.x][cell.y - 1] == k))
			&& (map[cell.x - 1][cell.y - 1] == 0)
			&& (map[cell.x + 1][cell.y - 1] == 0))
			return true;
		else
			return false;
	}

	if ((cell.x == size.x - 1) && (cell.y != 0))
	{
		if (((map[cell.x][cell.y - 1] == 0) || (map[cell.x][cell.y - 1] == k)) &&
			((map[cell.x][cell.y + 1] == 0) || (map[cell.x][cell.y + 1] == k)) &&
			((map[cell.x - 1][cell.y] == 0) || (map[cell.x - 1][cell.y] == k)) &&
			((map[cell.x][cell.y - 1] == k) || (map[cell.x][cell.y + 1] == k) || (map[cell.x - 1][cell.y] == k))
			&& (map[cell.x - 1][cell.y - 1] == 0)
			&& (map[cell.x - 1][cell.y + 1] == 0))
			return true;
		else
			return false;
	}

	if ((cell.x != 0) && (cell.y != 0))
	{
		if (((map[cell.x][cell.y - 1] == 0) || (map[cell.x][cell.y - 1] == k)) &&
			((map[cell.x][cell.y + 1] == 0) || (map[cell.x][cell.y + 1] == k)) &&
			((map[cell.x - 1][cell.y] == 0) || (map[cell.x - 1][cell.y] == k)) &&
			((map[cell.x + 1][cell.y] == 0) || (map[cell.x + 1][cell.y] == k)) &&
			((map[cell.x][cell.y - 1] == k) || (map[cell.x][cell.y + 1] == k)
				|| (map[cell.x - 1][cell.y] == k) || (map[cell.x + 1][cell.y] == k))
			&& (map[cell.x - 1][cell.y - 1] == 0) && (map[cell.x - 1][cell.y + 1] == 0)
			&& (map[cell.x + 1][cell.y - 1] == 0) && (map[cell.x + 1][cell.y + 1] == 0))
			return true;
		else
			return false;
	}
}

void GameMap::InitializationAllShips()
{
	for(int i = 0; i < size.x; i++)
		for (int j = 0; j < size.y; j++)
		{
			if (map[i][j] != 0)
				map[i][j] = 1;
		}
}

void GameMap::KillShip(Vector* cell, int n)
{
	for (int i = 0; i < n; i++)
	{
		map[cell[i].x][cell[i].y] = 3;

		if ((cell[i].x == 0) && (cell[i].y == 0))
		{   
			if (map[cell[i].x][cell[i].y + 1] == 0)
				map[cell[i].x][cell[i].y + 1] = -1;
			if (map[cell[i].x + 1][cell[i].y + 1] == 0)
				map[cell[i].x + 1][cell[i].y + 1] = -1;
			if (map[cell[i].x + 1][cell[i].y] == 0)
				map[cell[i].x + 1][cell[i].y] = -1;
		}

		if ((cell[i].x == 0) && (cell[i].y == size.y - 1))
		{
			if (map[cell[i].x][cell[i].y - 1] == 0)
				map[cell[i].x][cell[i].y - 1] = -1;
			if (map[cell[i].x + 1][cell[i].y - 1] == 0)
				map[cell[i].x + 1][cell[i].y - 1] = -1;
			if (map[cell[i].x + 1][cell[i].y] == 0)
				map[cell[i].x + 1][cell[i].y] = -1;
		}

		if ((cell[i].x == size.x - 1) && (cell[i].y == size.y - 1))
		{  
			if (map[cell[i].x - 1][cell[i].y] == 0)
				map[cell[i].x - 1][cell[i].y] = -1;
			if (map[cell[i].x - 1][cell[i].y - 1] == 0)
				map[cell[i].x - 1][cell[i].y - 1] = -1;
			if (map[cell[i].x][cell[i].y - 1] == 0)
				map[cell[i].x][cell[i].y - 1] = -1;
		}

		if ((cell[i].x == size.x - 1) && (cell[i].y == 0))
		{
			if (map[cell[i].x - 1][cell[i].y] == 0)
				map[cell[i].x - 1][cell[i].y] = -1;
			if (map[cell[i].x - 1][cell[i].y + 1] == 0)
				map[cell[i].x - 1][cell[i].y + 1] = -1;
			if (map[cell[i].x][cell[i].y + 1] == 0)
				map[cell[i].x][cell[i].y + 1] = -1;
		}

		if ((cell[i].y == 0) && (cell[i].x != 0) && (cell[i].x != size.x - 1))
		{   
			if (map[cell[i].x - 1][cell[i].y] == 0)
				map[cell[i].x - 1][cell[i].y] = -1;
			if (map[cell[i].x - 1][cell[i].y + 1] == 0)
				map[cell[i].x - 1][cell[i].y + 1] = -1;
			if (map[cell[i].x][cell[i].y + 1] == 0)
				map[cell[i].x][cell[i].y + 1] = -1;
			if (map[cell[i].x + 1][cell[i].y + 1] == 0)
				map[cell[i].x + 1][cell[i].y + 1] = -1;
			if (map[cell[i].x + 1][cell[i].y] == 0)
				map[cell[i].x + 1][cell[i].y] = -1;
		}

		if ((cell[i].x == 0) && (cell[i].y != 0) && (cell[i].y != size.x - 1))
		{
			if (map[cell[i].x][cell[i].y - 1] == 0)
				map[cell[i].x][cell[i].y - 1] = -1;
			if (map[cell[i].x + 1][cell[i].y - 1] == 0)
				map[cell[i].x + 1][cell[i].y - 1] = -1;
			if (map[cell[i].x + 1][cell[i].y] == 0)
				map[cell[i].x + 1][cell[i].y] = -1;
			if (map[cell[i].x + 1][cell[i].y + 1] == 0)
				map[cell[i].x + 1][cell[i].y + 1] = -1;
			if (map[cell[i].x][cell[i].y + 1] == 0)
				map[cell[i].x][cell[i].y + 1] = -1;
		}

		if ((cell[i].y == size.y - 1) && (cell[i].x != 0) && (cell[i].x != size.x - 1))
		{
			if (map[cell[i].x - 1][cell[i].y] == 0)
				map[cell[i].x - 1][cell[i].y] = -1;
			if (map[cell[i].x - 1][cell[i].y - 1] == 0)
				map[cell[i].x - 1][cell[i].y - 1] = -1;
			if (map[cell[i].x][cell[i].y - 1] == 0)
				map[cell[i].x][cell[i].y - 1] = -1;
			if (map[cell[i].x + 1][cell[i].y - 1] == 0)
				map[cell[i].x + 1][cell[i].y - 1] = -1;
			if (map[cell[i].x + 1][cell[i].y] == 0)
				map[cell[i].x + 1][cell[i].y] = -1;
		}

		if ((cell[i].x == size.x - 1) && (cell[i].y != 0) && (cell[i].y != size.y - 1))
		{
			if (map[cell[i].x][cell[i].y - 1] == 0)
				map[cell[i].x][cell[i].y - 1] = -1;
			if (map[cell[i].x - 1][cell[i].y - 1] == 0)
				map[cell[i].x - 1][cell[i].y - 1] = -1;
			if (map[cell[i].x - 1][cell[i].y] == 0)
				map[cell[i].x - 1][cell[i].y] = -1;
			if (map[cell[i].x - 1][cell[i].y + 1] == 0)
				map[cell[i].x - 1][cell[i].y + 1] = -1;
			if (map[cell[i].x][cell[i].y + 1] == 0)
				map[cell[i].x][cell[i].y + 1] = -1;
		}

		if ((cell[i].x != 0) && (cell[i].x != size.x - 1) && (cell[i].y != 0) && (cell[i].y != size.y - 1))
		{   
			if (map[cell[i].x][cell[i].y - 1] == 0)
				map[cell[i].x][cell[i].y - 1] = -1;
			if (map[cell[i].x - 1][cell[i].y - 1] == 0)
				map[cell[i].x - 1][cell[i].y - 1] = -1;
			if (map[cell[i].x - 1][cell[i].y] == 0)
				map[cell[i].x - 1][cell[i].y] = -1;
			if (map[cell[i].x - 1][cell[i].y + 1] == 0)
				map[cell[i].x - 1][cell[i].y + 1] = -1;
			if (map[cell[i].x][cell[i].y + 1] == 0)
				map[cell[i].x][cell[i].y + 1] = -1;
			if (map[cell[i].x + 1][cell[i].y + 1] == 0)
				map[cell[i].x + 1][cell[i].y + 1] = -1;
			if (map[cell[i].x + 1][cell[i].y] == 0)
				map[cell[i].x + 1][cell[i].y] = -1;
			if (map[cell[i].x + 1][cell[i].y - 1] == 0)
				map[cell[i].x + 1][cell[i].y - 1] = -1;

		}
	}
}





