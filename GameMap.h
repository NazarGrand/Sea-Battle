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
	GameMap(); // ������������
	GameMap(Vector);
	GameMap(int, int);
	~GameMap(); //����������

	bool SetPosition(Vector, int); //������ �������
	bool SetPositionForGame(Vector, int);
	bool IsEmpty(Vector); //������� �� ����� ������
	bool IsEmpty(int, int); //������� �� ����� ������
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

