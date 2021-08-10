#pragma once


#include<vector>
#include<algorithm>

struct Vector
{
	int x, y;
};


class GameMap
{
private:
	int** map;
	Vector size;

public:
	GameMap(); // конструктори
	GameMap(Vector);
	GameMap(int, int);
	~GameMap(); //деструктор

	bool SetPosition(Vector, int); //задать позиц≥ю
	bool SetPositionForGame(Vector, int);
	bool IsEmpty(Vector); //пров≥рка на в≥льну €чейку
	bool IsEmpty(int, int); //пров≥рка на в≥льну €чейку
	void SetMap(Vector);
	void SetMap(int, int);
	int GetValue(Vector);
	int GetValue(int, int);
	Vector GetSize() { return size; }
	int CheckingWin();
	bool CheckForShips(Vector, int);
	void InitializationAllShips();
	void KillShip(Vector*, int);
};

