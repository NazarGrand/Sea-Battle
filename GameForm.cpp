#include "GameForm.h"
#include "MyForm.h"
#include "Pal1.h"
#include "Pal2.h"
#include "Pal3.h"
#include "Pal4.h"
#include "Pal5.h"

#include<Windows.h>
#include<ColorDlg.h>


GameMap map1, map2;
Pal1 P1[5], C1[5];
Pal2 P2[4], C2[4];
Pal3 P3[3], C3[3];
Pal4 P4[2], C4[2];
Pal5 P5, C5;

Vector v5[5],v4[4],v3[3],v2[2],v1;
int i = 0, k = 1, number = 0;
int num_p1 = 5, num_p2 = 4, num_p3 = 3, num_p4 = 2, num_p5 = 1;
int num_c1 = 5, num_c2 = 4, num_c3 = 3, num_c4 = 2, num_c5 = 1;

bool startGame = false, endGame;

Vector V;
Vector v[4];
int n = 0, j;
int fl_x = 1, fl_y = 1;

enum GamerStatus
{
	Computer = 0,
	Player
};

Vector selectedCellPlayer;
GamerStatus currentPlayer = Player;


System::Void Fight::GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	label1->Visible = false;
	rows = 11; columns = 11;
	map1.SetMap(rows, columns);
	map2.SetMap(rows, columns);
	CreateGameGrid(map1.GetSize(), map2.GetSize());
	bool t = GenerateForComputerShips();

	while (t == false)
	{
	  map2.SetMap(rows, columns);
	  num_c1 = 5, num_c2 = 4, num_c3 = 3, num_c4 = 2, num_c5 = 1;
	  i = 0, k = 1, number = 0;
	  t = GenerateForComputerShips();
	}

	MessageBox::Show("Розставте кораблі!!!", "Увага!");

	if (startGame)
		NewGame();
}

void Fight::GameForm::CreateGameGrid(Vector size1, Vector size2)
{
	//очищуємо таблицю
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();

	//задаємо стиль
	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10);
	dataGridView1->DefaultCellStyle->Font = font;
	dataGridView1->ColumnHeadersDefaultCellStyle->Font = font;
	dataGridView1->RowHeadersDefaultCellStyle->Font = font;

	//створюємо всі стовпці
	for (int i = 0; i < size1.x; i++) {
		DataGridViewButtonColumn^ column = gcnew DataGridViewButtonColumn();
		column->HeaderCell->Value = Convert::ToString(i + 1); //виводить номети стовпців
		column->Name = "column" + i;
		column->Width = 35;

		dataGridView1->Columns->Add(column);
	}

	for (int i = 0; i < size1.y; i++) {
		dataGridView1->Rows->Add();
		dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1); //вивидить номери рядків
		dataGridView1->Rows[i]->Height = 35;
	}

	if(!startGame)
	dataGridView2->Visible = false;
	else
	dataGridView2->Visible = true;

	//очищуємо таблицю
	dataGridView2->Rows->Clear();
	dataGridView2->Columns->Clear();

	//задаємо стиль
	dataGridView2->DefaultCellStyle->Font = font;
	dataGridView2->ColumnHeadersDefaultCellStyle->Font = font;
	dataGridView2->RowHeadersDefaultCellStyle->Font = font;

	//створюємо всі стовпці
	for (int i = 0; i < size2.x; i++) {
		DataGridViewButtonColumn^ column = gcnew DataGridViewButtonColumn();
		column->HeaderCell->Value = Convert::ToString(i + 1);
		column->Name = "column" + i;
		column->Width = 35;

		dataGridView2->Columns->Add(column);
	}

	for (int i = 0; i < size1.y; i++) {
		dataGridView2->Rows->Add();
		dataGridView2->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView2->Rows[i]->Height = 35;
	}
}


bool Fight::GameForm::GenerateForComputerShips()
{ 
	rand = gcnew Random();
	int num_row, num_column;
	int t = 0;

	while (num_c5 > 0)
	{
		num_row = rand->Next(0, 11);
		num_column = rand->Next(0, 11);
		t++;

		if (t == 1000)
			return false;

		v5[i].x = num_row;
		v5[i].y = num_column;

		if (map2.CheckForShips(v5[i], k))
		{
			if (SetPositionComputer(v5[i], k))
			{
				number++;
				i++;
			}
		}
		if (number == 5)
		{
			C5.SetPosition(v5);
			num_c5 = 0;
			i = 0;
			k++;
			number = 0;
		}
	}
	 
	t = 0;
	while (num_c4 > 0)
	{
		num_row = rand->Next(0, 11);
		num_column = rand->Next(0, 11);

		t++;
		if (t == 1000)
			return false;

		v4[i].x = num_row;
		v4[i].y = num_column;

		if (map2.CheckForShips(v4[i], k))
		{
			if (SetPositionComputer(v4[i], k))
			{
				number++;
				i++;
			}
		}
		if (number == 4)
		{
			C4[num_c4 - 1].SetPosition(v4);
			num_c4--;
			i = 0;
			number = 0;
			k++;
		}
	}
	
	t = 0;
	while (num_c3 > 0)
	{
		num_row = rand->Next(0, 11);
		num_column = rand->Next(0, 11);

		t++;
		if (t == 1000)
			return false;

		v3[i].x = num_row;
		v3[i].y = num_column;

		if (map2.CheckForShips(v3[i], k))
		{
			if (SetPositionComputer(v3[i], k))
			{
				number++;
				i++;
			}
		}
		if (number == 3)
		{
			C3[num_c3 - 1].SetPosition(v3);
			num_c3--;
			i = 0;
			number = 0;
			k++;
		}
	}
	 
	t = 0;
	while (num_c2 > 0)
	{
		num_row = rand->Next(0, 11);
		num_column = rand->Next(0, 11);

		t++;
		if (t == 1000)
			return false;

		v2[i].x = num_row;
		v2[i].y = num_column;

		if (map2.CheckForShips(v2[i], k))
		{
			if (SetPositionComputer(v2[i], k))
			{
				number++;
				i++;
			}
		}
		if (number == 2)
		{
			C2[num_c2 - 1].SetPosition(v2);
			num_c2--;
			i = 0;
			number = 0;
			k++;
		}
	}

	t = 0;
	while (num_c1 > 0)
	{
		num_row = rand->Next(0, 11);
		num_column = rand->Next(0, 11);

		t++;
		if (t == 1000)
			return false;

		v1.x = num_row;
		v1.y = num_column;

		if (map2.CheckForShips(v1, k))
		{
			if (SetPositionComputer(v1, k))
			{
				number++;
				i++;
			}
		}
		if (number == 1)
		{
			C1[num_c1 - 1].SetPosition(v1);
			num_c1--;
			i = 0;
			number = 0;
			k++;
		}
	}

	UpdateForComputerGrid();
	i = 0, k = 1, number = 0;
	return true;
}

bool Fight::GameForm::SetPositionComputer(Vector cell, int m)
{
	if (map2.SetPosition(cell, m))
	{
		return true;
	}
	else
		return false;
}

System::Void Fight::GameForm::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	auto senderGrid = (DataGridView^)sender;//перетворюємо даний об'єкт в таблицю

	if (!startGame)
	{
		if ((radioButton1->Checked) && (num_p5 > 0))
		{
			//запам'ятовуємо індекси вибраної ячейки
			selectedCellPlayer.x = e->RowIndex;
			selectedCellPlayer.y = e->ColumnIndex;

			v5[i] = selectedCellPlayer;

			if (map1.CheckForShips(v5[i], k))
			{
				if (SetPositionPlayer(v5[i], k))
				{
					number++;
					i++;
				}
			}
			if (number == 5)
			{
				P5.SetPosition(v5);
				num_p5 = 0;
				label4->Text = Convert::ToString(num_p5);
				i = 0;
				k++;
				number = 0;
				radioButton1->Checked = false;
			}
		}

		if ((radioButton2->Checked) && (num_p4 > 0))
		{
			//запам'ятовуємо індекси вибраної ячейки
			selectedCellPlayer.x = e->RowIndex;
			selectedCellPlayer.y = e->ColumnIndex;

			v4[i] = selectedCellPlayer;

			if (map1.CheckForShips(v4[i], k))
			{
				if (SetPositionPlayer(v4[i], k))
				{
					number++;
					i++;
				}
			}
			if (number == 4)
			{
				P4[num_p4 - 1].SetPosition(v4);
				num_p4--;
				label5->Text = Convert::ToString(num_p4);
				i = 0;
				number = 0;
				k++;
				radioButton2->Checked = false;
			}
		}

		if ((radioButton3->Checked) && (num_p3 > 0))
		{
			//запам'ятовуємо індекси вибраної ячейки
			selectedCellPlayer.x = e->RowIndex;
			selectedCellPlayer.y = e->ColumnIndex;

			v3[i] = selectedCellPlayer;

			if (map1.CheckForShips(v3[i], k))
			{
				if (SetPositionPlayer(v3[i], k))
				{
					number++;
					i++;
				}
			}
			if (number == 3)
			{
				P3[num_p3 - 1].SetPosition(v3);
				num_p3--;
				label6->Text = Convert::ToString(num_p3);
				i = 0;
				number = 0;
				k++;
				radioButton3->Checked = false;
			}
		}

		if ((radioButton4->Checked) && (num_p2 > 0))
		{
			//запам'ятовуємо індекси вибраної ячейки
			selectedCellPlayer.x = e->RowIndex;
			selectedCellPlayer.y = e->ColumnIndex;

			v2[i] = selectedCellPlayer;

			if (map1.CheckForShips(v2[i], k))
			{
				if (SetPositionPlayer(v2[i], k))
				{
					number++;
					i++;
				}
			}
			if (number == 2)
			{
				P2[num_p2 - 1].SetPosition(v2);
				num_p2--;
				label7->Text = Convert::ToString(num_p2);
				i = 0;
				number = 0;
				k++;
				radioButton4->Checked = false;
			}
		}

		if ((radioButton5->Checked) && (num_p1 > 0))
		{
			//запам'ятовуємо індекси вибраної ячейки
			selectedCellPlayer.x = e->RowIndex;
			selectedCellPlayer.y = e->ColumnIndex;

			v1 = selectedCellPlayer;

			if (map1.CheckForShips(v1, k))
			{
				if (SetPositionPlayer(v1, k))
				{
					number++;
					i++;
				}
			}
			if (number == 1)
			{
				P1[num_p1 - 1].SetPosition(v1);
				num_p1--;
				label8->Text = Convert::ToString(num_p1);
				i = 0;
				number = 0;
				k++;
				radioButton5->Checked = false;
			}
		}
	}
}

bool Fight::GameForm::SetPositionPlayer(Vector cell, int m)
{
	if (currentPlayer == Player)
	{ //робимо хід
		if (!map1.SetPosition(cell, m))
		{
			MessageBox::Show("Дана позиція занята!", "Увага!");
			return false;
		}
	}
	else
	{
		MessageBox::Show("Ще не ваша черга!", "Увага!");
	}
	if (startGame)
		Update();
	else
	{
		UpdateForPlayerGrid();
		return true;
	}
}

void Fight::GameForm::UpdateForPlayerGrid()
{
	for (int i = 0; i < map1.GetSize().x; i++) {
		for (int j = 0; j < map1.GetSize().y; j++) {
			if (!map1.IsEmpty(i, j)) {
				if (map1.GetValue(i, j) != 0) {
					dataGridView1->Rows[i]->Cells[j]->Value = "X";
				}
			}
		}
	}
}

System::Void Fight::GameForm::button1_Click(System::Object^ sender, System::EventArgs^ e) //кнопка Start Game
{
	if ((num_p1 == 0) && (num_p2 == 0) && (num_p3 == 0) && (num_p4 == 0) && (num_p5 == 0))
	{
		startGame = true;
		label2->Visible = false;
		label3->Visible = false;
		label4->Visible = false;
		label5->Visible = false;
		label6->Visible = false;
		label7->Visible = false;
		label8->Visible = false;
		radioButton1->Visible = false;
		radioButton2->Visible = false;
		radioButton3->Visible = false;
		radioButton4->Visible = false;
		radioButton5->Visible = false;
		button1->Visible = false;
		button2->Visible = false;
		label1->Text = "Хід Гравця!";
		label10->Text = "Хід Комп'ютера!";
		NewGame();
	}
	else
		MessageBox::Show("Ви не розставили всі кораблі!", "Увага!");
}

System::Void Fight::GameForm::button2_Click(System::Object^ sender, System::EventArgs^ e) //кнопка Reset
{
	 i = 0, k = 1, number = 0;
     num_p1 = 5, num_p2 = 4, num_p3 = 3, num_p4 = 2, num_p5 = 1;
	 rows = 11; columns = 11;
	 map1.SetMap(rows, columns);

	 label4->Text = Convert::ToString(num_p5);
	 label5->Text = Convert::ToString(num_p4);
	 label6->Text = Convert::ToString(num_p3);
	 label7->Text = Convert::ToString(num_p2);
	 label8->Text = Convert::ToString(num_p1);
	 radioButton1->Checked = false;
	 radioButton2->Checked = false;
	 radioButton3->Checked = false;
	 radioButton4->Checked = false;
	 radioButton5->Checked = false;

	 CreateGameGrid(map1.GetSize(), map2.GetSize());
}

void Fight::GameForm::NewGame()
{   
	//ініціалізуємо дані
	label9->Visible = false;
	map1.InitializationAllShips();
	map2.InitializationAllShips();
	rand = gcnew Random();
	endGame = false;

	CreateGameGrid(map1.GetSize(), map2.GetSize()); //створюємо ігрове поле

	//порядок ходьби гравця і комп'ютера
	int state_gamer = rand->Next(1, 3);
	if (state_gamer == 1)
  	{
		label10->Visible = false;
		label1->Visible = true;

		currentPlayer = Player;
	}
	else
	{
		label1->Visible = false;
		label10->Visible = true;

		currentPlayer = Computer;

		GameLogic();
		UpdateGameGrid();
	}
}

void Fight::GameForm::GameLogic()
{
	bool b;
	if (currentPlayer == Computer) {
		b = StepAI();

		while (b)
		{
			b = StepAI();
		}
	}

	Update();
}

void Fight::GameForm::Update()
{    
	if (currentPlayer == Computer)
	{
		label1->Visible = true;
		label10->Visible = false;
		currentPlayer = Player;
		return;
	}
	else
	{
		label1->Visible = false;
		label10->Visible = true;
		//Sleep(3000);
		currentPlayer = Computer;
		GameLogic();
		UpdateGameGrid();
	}
}

bool Fight::GameForm::StepAI()
{
	int state_game = map1.CheckingWin();
	if (state_game == 1)
	{
		MessageBox::Show("Вітаємо комп'ютер з перемогою!", "Перемога!");

		UpdateGameGrid();

		endGame = true;

		Application::Exit();
	}

	state_game = map2.CheckingWin();
	if (state_game == 1)
	{
		MessageBox::Show("Вітаємо гравця з перемогою!", "Перемога!");

		UpdateGameGrid();

		endGame = true;

		Application::Exit();
	}

	fl_x = 1; fl_y = 1;
	n = 0;
	for (i = 0; i < map1.GetSize().x; i++)
	{
		for (j = 0; j < map1.GetSize().y; j++)
		{
			if (map1.GetValue(i, j) == 2)
			{
				v[n].x = i;
				v[n].y = j;
				n++;
			}
		}
	}
	if (n == 1)
	{
		if ((v[0].x - 1) != -1)
		{
			if ((map1.GetValue(v[0].x - 1, v[0].y) == 1) || (map1.GetValue(v[0].x - 1, v[0].y) == 0))
			{
				V.x = v[0].x - 1;
				V.y = v[0].y;
			}
		}
		if ((v[0].x + 1) != map1.GetSize().x)
		{
			if ((map1.GetValue(v[0].x + 1, v[0].y) == 1) || (map1.GetValue(v[0].x + 1, v[0].y) == 0))
			{
				V.x = v[0].x + 1;
				V.y = v[0].y;
			}
		}

		if ((v[0].y - 1) != -1)
		{
			if ((map1.GetValue(v[0].x, v[0].y - 1) == 1) || (map1.GetValue(v[0].x, v[0].y - 1) == 0))
			{
				V.x = v[0].x;
				V.y = v[0].y - 1;
			}
		}

		if ((v[0].y + 1) != map1.GetSize().y)
		{
			if ((map1.GetValue(v[0].x, v[0].y + 1) == 1) || (map1.GetValue(v[0].x, v[0].y + 1) == 0))
			{
				V.x = v[0].x;
				V.y = v[0].y + 1;
			}
		}
	}

	if (n > 1)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (v[i].x != v[i + 1].x)
				fl_x = 0;
			if (v[i].y != v[i + 1].y)
				fl_y = 0;
		}

		int min_x = v[0].x, max_x = v[0].x, min_y = v[0].y, max_y = v[0].y;
		if (fl_x == 1)
		{
			for (int i = 1; i < n; i++)
			{
				if (min_y > v[i].y)
					min_y = v[i].y;
				if (max_y < v[i].y)
					max_y = v[i].y;
			}

			if (min_y - 1 != -1)
			{
				if ((map1.GetValue(v[0].x, min_y - 1) == 1) || (map1.GetValue(v[0].x, min_y - 1) == 0))
				{
					V.x = v[0].x;
					V.y = min_y - 1;
				}
			}

			if (max_y + 1 != map1.GetSize().y)
			{
				if ((map1.GetValue(v[0].x, max_y + 1) == 1) || (map1.GetValue(v[0].x, max_y + 1) == 0))
				{
					V.x = v[0].x;
					V.y = max_y + 1;
				}
			}
		}

		if (fl_y == 1)
		{
			for (int i = 1; i < n; i++)
			{
				if (min_x > v[i].x)
					min_x = v[i].x;
				if (max_x < v[i].x)
					max_x = v[i].x;
			}

			if (min_x - 1 != -1)
			{
				if ((map1.GetValue(min_x - 1, v[0].y) == 1) || (map1.GetValue(min_x - 1, v[0].y) == 0))
				{
					V.x = min_x - 1;
					V.y = v[0].y;
				}
			}

			if (max_x + 1 != map1.GetSize().x)
			{
				if ((map1.GetValue(max_x + 1, v[0].y) == 1) || (map1.GetValue(max_x + 1, v[0].y) == 0))
				{
					V.x = max_x + 1;
					V.y = v[0].y;
				}
			}
		}
	}

	if(  (n == 0))
	{
		V.x = rand->Next(0, 11);
		V.y = rand->Next(0, 11);

		while ((map1.GetValue(V) == -1) || (map1.GetValue(V) == 3))
		{
			V.x = rand->Next(0, 11);
			V.y = rand->Next(0, 11);
		}
	}

	if (map1.GetValue(V.x, V.y) == -1)
	{
		return true;
	}

	if (map1.GetValue(V.x, V.y) == 2)
	{
		return true;
	}

	if (map1.GetValue(V.x, V.y) == 3)
	{
		return true;
	}

	//Робимо хід
	if (map1.GetValue(V.x, V.y) == 0)
	{
		if (map1.SetPositionForGame(V, -1))
		{
			UpdateGameGrid();
		}
		return false;
	}

	if (map1.GetValue(V.x, V.y) == 1)
	{
		if (map1.SetPositionForGame(V, 2))
		{
			UpdateGameGrid();
		}

		for (int i = 0; i < 5; i++)
		{
			if (P1[i].FindPal(V))
			{
				if (P1[i].GetNumber() == 1)
				{
					v1 = P1[i].GetValue();
					map1.KillShip(&v1, 1);
					UpdateGameGrid();
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (P2[i].FindPal(V))
			{
				if (P2[i].GetNumber() == 2)
				{
					for (int k = 0; k < 2; k++)
						v2[k] = P2[i].GetValue(k);
					map1.KillShip(v2, 2);
					UpdateGameGrid();
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (P3[i].FindPal(V))
			{
				if (P3[i].GetNumber() == 3)
				{
					for (int k = 0; k < 3; k++)
						v3[k] = P3[i].GetValue(k);
					map1.KillShip(v3, 3);
					UpdateGameGrid();
				}
			}
		}

		for (int i = 0; i < 2; i++)
		{
			if (P4[i].FindPal(V))
			{
				if (P4[i].GetNumber() == 4)
				{
					for (int k = 0; k < 4; k++)
						v4[k] = P4[i].GetValue(k);
					map1.KillShip(v4, 4);
					UpdateGameGrid();
				}
			}
		}

		if (P5.FindPal(V))
		{
			if (P5.GetNumber() == 5)
			{
				for (int k = 0; k < 5; k++)
					v5[k] = P5.GetValue(k);
				map1.KillShip(v5, 5);
				UpdateGameGrid();
			}
		}
		return true;
	}
}

void Fight::GameForm::UpdateGameGrid()
{
	for (int i = 0; i < map1.GetSize().x; i++) {
		for (int j = 0; j < map1.GetSize().y; j++) {
			if (!map1.IsEmpty(i, j)) {
				if (map1.GetValue(i, j) == 3)
				{
					dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Red;
				}
				if (map1.GetValue(i, j) == 2) {
					{
						dataGridView1->Rows[i]->Cells[j]->Value = "X";
					}
				}
				if (map1.GetValue(i, j) == -1)
					dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Blue;
			}
		}
	}

	for (int i = 0; i < map2.GetSize().x; i++) {
		for (int j = 0; j < map2.GetSize().y; j++) {
			if (!map2.IsEmpty(i, j)) {

				if (map2.GetValue(i, j) == 3)
				{
					dataGridView2->Rows[i]->Cells[j]->Style->BackColor = Color::Red;
				}
				if (map2.GetValue(i, j) == 2) {
					{
					dataGridView2->Rows[i]->Cells[j]->Value = "X";
					}
				}
				if (map2.GetValue(i, j) == -1)
					dataGridView2->Rows[i]->Cells[j]->Style->BackColor = Color::Blue;
			}
		}
	}
}

void Fight::GameForm::UpdateForComputerGrid()
{
	for (int i = 0; i < map2.GetSize().x; i++) {
		for (int j = 0; j < map2.GetSize().y; j++) {
			if (!map2.IsEmpty(i, j)) {
				if (map2.GetValue(i, j) != 0) {
					dataGridView2->Rows[i]->Cells[j]->Value = "X";
				}
			}
		}
	}
}

System::Void Fight::GameForm::dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	auto senderGrid = (DataGridView^)sender;//перетворюємо даний об'єкт в таблицю

	//запам'ятовуємо індекси вибраної ячейки
	selectedCellPlayer.x = e->RowIndex;
	selectedCellPlayer.y = e->ColumnIndex;

	if (map2.GetValue(selectedCellPlayer.x, selectedCellPlayer.y) == -1)
	{
		MessageBox::Show("Дана позиція зайнята!", "Увага!");
		return;
	}

	if (map2.GetValue(selectedCellPlayer.x, selectedCellPlayer.y) == 2)
	{
		MessageBox::Show("Дана позиція зайнята!", "Увага!");
		return;
	}

	if (map2.GetValue(selectedCellPlayer.x, selectedCellPlayer.y) == 3)
	{
		MessageBox::Show("Дана позиція зайнята!", "Увага!");
		return;
	}

	//Робимо хід
	if (map2.GetValue(selectedCellPlayer.x, selectedCellPlayer.y) == 0)
	{
		if (map2.SetPositionForGame(selectedCellPlayer, -1))
		{
			UpdateGameGrid();
		}
		Update();
	}
	if (map2.GetValue(selectedCellPlayer.x, selectedCellPlayer.y) == 1)
	{
		if (map2.SetPositionForGame(selectedCellPlayer, 2))
		{
			UpdateGameGrid();
		 }
         
		for (int i = 0; i < 5; i++)
		{
			if (C1[i].FindPal(selectedCellPlayer))
			{
				if (C1[i].GetNumber() == 1)
				{
					v1 = C1[i].GetValue();
					map2.KillShip(&v1, 1);
					UpdateGameGrid();
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (C2[i].FindPal(selectedCellPlayer))
			{
				if (C2[i].GetNumber() == 2)
				{   
					for (int k = 0; k < 2; k++)
					v2[k] = C2[i].GetValue(k);
					map2.KillShip(v2, 2);
					UpdateGameGrid();
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (C3[i].FindPal(selectedCellPlayer))
			{
				if (C3[i].GetNumber() == 3)
					{
					for (int k = 0; k < 3; k++)
						v3[k] = C3[i].GetValue(k);
						map2.KillShip(v3, 3);
						UpdateGameGrid();
				     }
			}
		}

		for (int i = 0; i < 2; i++)
		{
			if (C4[i].FindPal(selectedCellPlayer))
			{
				if (C4[i].GetNumber() == 4)
				{   
					for (int k = 0; k < 4; k++)
					v4[k] = C4[i].GetValue(k);
					map2.KillShip(v4, 4);
					UpdateGameGrid();
				}
			}
		}

		if (C5.FindPal(selectedCellPlayer))
		{
			if (C5.GetNumber() == 5)
			{   
				for (int k = 0; k < 5; k++)
				v5[k] = C5.GetValue(k);
				map2.KillShip(v5, 5);
				UpdateGameGrid();
			}
		}

     }

	int state_game = map1.CheckingWin();
	if (state_game == 1)
	{
		MessageBox::Show("Вітаємо комп'ютер з перемогою!", "Перемога!");

		UpdateGameGrid();

		endGame = true;

		Application::Exit();
	}

   state_game = map2.CheckingWin();
	if (state_game == 1)
	{
		MessageBox::Show("Вітаємо гравця з перемогою!", "Перемога!");

		UpdateGameGrid();

		endGame = true;

		Application::Exit();
	}
}

