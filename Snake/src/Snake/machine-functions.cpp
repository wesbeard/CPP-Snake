#include "snake.h"

void Snake::machineMove()
{
	int i;
	dir = STOP;
	bool moved = false;
	bool safeLeft = true;
	bool safeRight = true;
	bool safeUp = true;
	bool safeDown = true;
	bool twoSafeLeft = true;
	bool twoSafeRight = true;
	bool twoSafeUp = true;
	bool twoSafeDown = true;
	bool threeSafeLeft = true;
	bool threeSafeRight = true;
	bool threeSafeUp = true;
	bool threeSafeDown = true;
	bool fourSafeLeft = true;
	bool fourSafeRight = true;
	bool fourSafeUp = true;
	bool fourSafeDown = true;

	//Evaluates safe moves
	//One safe
	for (i = 0; i < nTail; i++)
	{
		if ((tailX[i] == (x + 2) && tailY[i] == y) || x == 38)
		{
			safeRight = false;
		}
		if ((tailX[i] == (x - 2) && tailY[i] == y) || x == 0)
		{
			safeLeft = false;
		}
		if ((tailY[i] == (y - 1) && tailX[i] == x) || y == 0)
		{
			safeUp = false;
		}
		if ((tailY[i] == (y + 1) && tailX[i] == x) || y == 19)
		{
			safeDown = false;
		}

	}
	//Two Safe
	for (i = 0; i < nTail; i++)
	{
		if ((tailX[i] == (x + 4) && tailY[i] == y) || x == 36)
		{
			twoSafeRight = false;
		}
		if ((tailX[i] == (x - 4) && tailY[i] == y) || x == 2)
		{
			twoSafeLeft = false;
		}
		if ((tailY[i] == (y - 2) && tailX[i] == x) || y == 1)
		{
			twoSafeUp = false;
		}
		if ((tailY[i] == (y + 2) && tailX[i] == x) || y == 18)
		{
			twoSafeDown = false;
		}
	}
	//Three safe
	for (i = 0; i < nTail; i++)
	{
		if ((tailX[i] == (x + 6) && tailY[i] == y) || x == 34)
		{
			threeSafeRight = false;
		}
		if ((tailX[i] == (x - 6) && tailY[i] == y) || x == 4)
		{
			threeSafeLeft = false;
		}
		if ((tailY[i] == (y - 3) && tailX[i] == x) || y == 2)
		{
			threeSafeUp = false;
		}
		if ((tailY[i] == (y + 3) && tailX[i] == x) || y == 17)
		{
			threeSafeDown = false;
		}
	}
	//Four safe
	for (i = 0; i < nTail; i++)
	{
		if ((tailX[i] == (x + 8) && tailY[i] == y) || x == 32)
		{
			fourSafeRight = false;
		}
		if ((tailX[i] == (x - 8) && tailY[i] == y) || x == 6)
		{
			fourSafeLeft = false;
		}
		if ((tailY[i] == (y - 4) && tailX[i] == x) || y == 3)
		{
			fourSafeUp = false;
		}
		if ((tailY[i] == (y + 4) && tailX[i] == x) || y == 16)
		{
			fourSafeDown = false;
		}
	}

	//MOVING
	//Evaluates the safest possible move to get to the fruit

	//FOUR SAFE MOVE
	if (moved != true)
	{
		if (fruitX < x && safeLeft == true && twoSafeLeft == true && threeSafeLeft == true && fourSafeLeft)
		{
			cout << "Four Safe Moving LEFT     " << endl;
			dir = LEFT;
			moved = true;
		}
		else if (fruitX > x && safeRight == true && twoSafeRight == true && threeSafeRight == true && fourSafeRight)
		{
			cout << "Four Safe Moving RIGHT    " << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (fruitY < y && safeUp == true && twoSafeUp == true && threeSafeUp == true && fourSafeUp)
		{
			cout << "Four Safe Moving UP    " << endl;
			dir = UP;
			moved = true;
		}
		else if (fruitY > y && safeDown == true && twoSafeDown == true && threeSafeDown == true && fourSafeDown)
		{
			cout << "Four Safe Moving DOWN     " << endl;
			dir = DOWN;
			moved = true;
		}
	}
	if (moved == true)
	{
		update();
	}
	//THREE SAFE MOVE
	if (moved != true)
	{
		if (fruitX < x && safeLeft == true && twoSafeLeft == true && threeSafeLeft == true)
		{
			cout << "Three Safe Moving LEFT" << endl;
			dir = LEFT;
			moved = true;
		}
		else if (fruitX > x && safeRight == true && twoSafeRight == true && threeSafeRight == true)
		{
			cout << "Three Safe Moving RIGHT" << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (fruitY < y && safeUp == true && twoSafeUp == true && threeSafeUp == true)
		{
			cout << "Three Safe Moving UP" << endl;
			dir = UP;
			moved = true;
		}
		else if (fruitY > y && safeDown == true && twoSafeDown == true && threeSafeDown == true)
		{
			cout << "Three Safe Moving DOWN" << endl;
			dir = DOWN;
			moved = true;
		}

	}
	if (moved == true)
	{
		update();
	}
	//TWO SAFE MOVE
	if (moved != true)
	{
		if (fruitX < x && safeLeft == true && twoSafeLeft == true)
		{
			cout << "Two Safe Moving LEFT" << endl;
			dir = LEFT;
			moved = true;
		}
		else if (fruitX > x && safeRight == true && twoSafeRight == true)
		{
			cout << "Two Safe Moving RIGHT" << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (fruitY < y && safeUp == true && twoSafeUp == true)
		{
			cout << "Two Safe Moving UP" << endl;
			dir = UP;
			moved = true;

		}
		else if (fruitY > y && safeDown == true && twoSafeDown == true)
		{
			cout << "Two Safe Moving DOWN" << endl;
			dir = DOWN;
			moved = true;
		}

	}
	if (moved == true)
	{
		update();
	}
	//SAFE MOVE
	if (moved != true)
	{
		if (fruitX < x && safeLeft == true)
		{
			cout << "Moving LEFT" << endl;
			dir = LEFT;
			moved = true;

		}
		else if (fruitX > x && safeRight == true)
		{
			cout << "Moving RIGHT" << endl;
			dir = RIGHT;
			moved = true;

		}
		else if (fruitY < y && safeUp == true)
		{
			cout << "Moving UP" << endl;
			dir = UP;
			moved = true;
		}
		else if (fruitY > y && safeDown == true)
		{
			cout << "Moving DOWN" << endl;
			dir = DOWN;
			moved = true;
		}
	}

	//DODGING
	//If no safe movement is available the safest dodge will be taken

	//FOUR SAFE DODGE
	if (moved != true)
	{
		if (safeLeft == true && twoSafeLeft == true && threeSafeLeft == true && fourSafeLeft)
		{
			cout << "Four Safe Dodging LEFT" << endl;
			dir = LEFT;
			moved = true;
		}
		else if (safeRight == true && twoSafeRight == true && threeSafeRight == true && fourSafeRight)
		{
			cout << "Four Safe Dodging RIGHT" << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (safeUp == true && twoSafeUp == true && threeSafeUp == true && fourSafeUp)
		{
			cout << "Four Safe Dodging UP" << endl;
			dir = UP;
			moved = true;
		}
		else if (safeDown == true && twoSafeDown == true && threeSafeDown == true && fourSafeDown)
		{
			cout << "Four Safe Dodging DOWN" << endl;
			dir = DOWN;
			moved = true;
		}
	}
	if (moved == true)
	{
		update();
	}
	//THREE SAFE DODGE
	if (moved != true)
	{
		if (safeLeft == true && twoSafeLeft == true && threeSafeLeft == true)
		{
			cout << "Three Safe Dodging LEFT" << endl;
			dir = LEFT;
			moved = true;
		}
		else if (safeRight == true && twoSafeRight == true && threeSafeRight == true)
		{
			cout << "Three Safe Dodging RIGHT" << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (safeUp == true && twoSafeUp == true && threeSafeUp == true)
		{
			cout << "Three Safe Dodging UP" << endl;
			dir = UP;
			moved = true;
		}
		else if (safeDown == true && twoSafeDown == true && threeSafeDown == true)
		{
			cout << "Three Safe Dodging DOWN" << endl;
			dir = DOWN;
			moved = true;
		}
	}
	if (moved == true)
	{
		update();
	}
	//TWO SAFE DODGE
	if (moved != true)
	{
		if (safeLeft == true && twoSafeLeft == true)
		{
			cout << "Two Safe Dodging LEFT" << endl;
			dir = LEFT;
			moved = true;
		}
		else if (safeRight == true && twoSafeRight == true)
		{
			cout << "Two Safe Dodging RIGHT" << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (safeUp == true && twoSafeUp == true)
		{
			cout << "Two Safe Dodging UP" << endl;
			dir = UP;
			moved = true;

		}
		else if (safeDown == true && twoSafeDown == true)
		{
			cout << "Two Safe Dodging DOWN" << endl;
			dir = DOWN;
			moved = true;

		}
	}
	if (moved == true)
	{
		update();
	}
	//SAFE DODGE
	if (moved != true)
	{
		if (safeLeft == true)
		{
			cout << "Dodging LEFT" << endl;
			dir = LEFT;
			moved = true;

		}
		else if (safeRight == true)
		{
			cout << "Dodging RIGHT" << endl;
			dir = RIGHT;
			moved = true;

		}
		else if (safeUp == true)
		{
			cout << "Dodging UP" << endl;
			dir = UP;
			moved = true;
		}
		else if (safeDown == true)
		{
			cout << "Dodging DOWN" << endl;
			dir = DOWN;
			moved = true;

		}
	}

	//Waits for keyboard input
	if (_kbhit())
	{
		//Checks for pause or exit key presses
		switch (_getch())
		{
		case 'x':
			gameOver = true;
			system("pause");
			system("cls");
			break;
		case 'p':
			pause();
			break;
		}
	}
}

void Snake::firstMachine()
{
	//RIGHT
	if (fruitX > x)
	{
		cout << "Moving RIGHT" << endl;
		dir = RIGHT;
	}

	//LEFT
	if (fruitX < x)
	{
		cout << "Moving LEFT" << endl;
		dir = LEFT;
	}

	if (_kbhit())
	{
		//Translates keyboard input
		switch (_getch())
		{
		case 'x':
			gameOver = true;
			machineStage++;
			newGame = true;
			cout << "Stage One Ended" << endl;
			system("pause");
			system("cls");
			break;
		case 'p':
			pause();
			break;
		}
	}
}

void Snake::secondMachine()
{
	//RIGHT
	if (fruitX > x)
	{
		cout << "Moving RIGHT" << endl;
		dir = RIGHT;
	}

	//LEFT
	if (fruitX < x)
	{
		cout << "Moving LEFT" << endl;
		dir = LEFT;
	}

	//DOWN
	if (fruitY > y)
	{
		cout << "Moving DOWN" << endl;
		dir = DOWN;
	}

	//UP
	if (fruitY < y)
	{
		cout << "Moving UP" << endl;
		dir = UP;
	}

	if (_kbhit())
	{
		//Translates keyboard input
		switch (_getch())
		{
		case 'x':
			gameOver = true;
			machineStage++;
			newGame = true;
			cout << "Stage Two Ended" << endl;
			system("pause");
			system("cls");
			break;
		case 'p':
			pause();
			break;
		}
	}
}

void Snake::thirdMachine()
{
	bool moved = false;
	bool safeLeft = true;
	bool safeRight = true;
	bool safeUp = true;
	bool safeDown = true;
	int i;

	//Evaluates safe moves
	for (i = 0; i < nTail; i++)
	{
		if ((tailX[i] == (x + 2) && tailY[i] == y) || x == 38)
		{
			safeRight = false;
		}
		if ((tailX[i] == (x - 2) && tailY[i] == y) || x == 0)
		{ 
			safeLeft = false;
		}
		if ((tailY[i] == (y - 1) && tailX[i] == x) || y == 0)
		{
			safeUp = false;
		}
		if ((tailY[i] == (y + 1) && tailX[i] == x) || y == 19)
		{
			safeDown = false;
		}
	}

	//RIGHT
	if (fruitX > x && safeRight == true)
	{
		cout << "Moving RIGHT" << endl;
		dir = RIGHT;
		moved = true;
	}

	//LEFT
	if (fruitX < x && safeLeft == true)
	{
		cout << "Moving LEFT" << endl;
		dir = LEFT;
		moved = true;
	}

	//DOWN
	if (fruitY > y && safeDown == true)
	{
		cout << "Moving DOWN" << endl;
		dir = DOWN;
		moved = true;
	}

	//UP
	if (fruitY < y && safeUp == true)
	{
		cout << "Moving UP" << endl;
		dir = UP;
		moved = true;
	}

	if (_kbhit())
	{
		//Translates keyboard input
		switch (_getch())
		{
		case 'x':
			gameOver = true;
			machineStage++;
			newGame = true;
			cout << "Stage Three Ended" << endl;
			system("pause");
			system("cls");
			break;
		case 'p':
			pause();
			break;
		}
	}
}

void Snake::fourthMachine()
{
	int i;
	dir = STOP;
	bool moved = false;
	bool safeLeft = true;
	bool safeRight = true;
	bool safeUp = true;
	bool safeDown = true;
	bool twoSafeLeft = true;
	bool twoSafeRight = true;
	bool twoSafeUp = true;
	bool twoSafeDown = true;
	bool threeSafeLeft = true;
	bool threeSafeRight = true;
	bool threeSafeUp = true;
	bool threeSafeDown = true;
	bool fourSafeLeft = true;
	bool fourSafeRight = true;
	bool fourSafeUp = true;
	bool fourSafeDown = true;

	//Evaluates safe moves
	//One safe
	for (i = 0; i < nTail; i++)
	{
		if ((tailX[i] == (x + 2) && tailY[i] == y) || x == 38)
		{
			safeRight = false;
		}
		if ((tailX[i] == (x - 2) && tailY[i] == y) || x == 0)
		{
			safeLeft = false;
		}
		if ((tailY[i] == (y - 1) && tailX[i] == x) || y == 0)
		{
			safeUp = false;
		}
		if ((tailY[i] == (y + 1) && tailX[i] == x) || y == 19)
		{
			safeDown = false;
		}

	}
	//Two Safe
	for (i = 0; i < nTail; i++)
	{
		if ((tailX[i] == (x + 4) && tailY[i] == y) || x == 36)
		{
			twoSafeRight = false;
		}
		if ((tailX[i] == (x - 4) && tailY[i] == y) || x == 2)
		{
			twoSafeLeft = false;
		}
		if ((tailY[i] == (y - 2) && tailX[i] == x) || y == 1)
		{
			twoSafeUp = false;
		}
		if ((tailY[i] == (y + 2) && tailX[i] == x) || y == 18)
		{
			twoSafeDown = false;
		}
	}
	//Three safe
	for (i = 0; i < nTail; i++)
	{
		if ((tailX[i] == (x + 6) && tailY[i] == y) || x == 34)
		{
			threeSafeRight = false;
		}
		if ((tailX[i] == (x - 6) && tailY[i] == y) || x == 4)
		{
			threeSafeLeft = false;
		}
		if ((tailY[i] == (y - 3) && tailX[i] == x) || y == 2)
		{
			threeSafeUp = false;
		}
		if ((tailY[i] == (y + 3) && tailX[i] == x) || y == 17)
		{
			threeSafeDown = false;
		}
	}
	//Four safe
	for (i = 0; i < nTail; i++)
	{
		if ((tailX[i] == (x + 8) && tailY[i] == y) || x == 32)
		{
			fourSafeRight = false;
		}
		if ((tailX[i] == (x - 8) && tailY[i] == y) || x == 6)
		{
			fourSafeLeft = false;
		}
		if ((tailY[i] == (y - 4) && tailX[i] == x) || y == 3)
		{
			fourSafeUp = false;
		}
		if ((tailY[i] == (y + 4) && tailX[i] == x) || y == 16)
		{
			fourSafeDown = false;
		}
	}

	//MOVING
	//FOUR SAFE MOVE
	if (moved != true)
	{
		if (fruitX < x && safeLeft == true && twoSafeLeft == true && threeSafeLeft == true && fourSafeLeft)
		{
			cout << "Four Safe Moving LEFT" << endl;
			dir = LEFT;
			moved = true;
		}
		else if (fruitX > x && safeRight == true && twoSafeRight == true && threeSafeRight == true && fourSafeRight)
		{
			cout << "Four Safe Moving RIGHT" << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (fruitY < y && safeUp == true && twoSafeUp == true && threeSafeUp == true && fourSafeUp)
		{
			cout << "Four Safe Moving UP" << endl;
			dir = UP;
			moved = true;
		}
		else if (fruitY > y && safeDown == true && twoSafeDown == true && threeSafeDown == true && fourSafeDown)
		{
			cout << "Four Safe Moving DOWN" << endl;
			dir = DOWN;
			moved = true;
		}
	}
	if (moved == true)
	{
		update();
	}
	//THREE SAFE MOVE
	if (moved != true)
	{
		if (fruitX < x && safeLeft == true && twoSafeLeft == true && threeSafeLeft == true)
		{
			cout << "Three Safe Moving LEFT" << endl;
			dir = LEFT;
			moved = true;
		}
		else if (fruitX > x && safeRight == true && twoSafeRight == true && threeSafeRight == true)
		{
			cout << "Three Safe Moving RIGHT" << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (fruitY < y && safeUp == true && twoSafeUp == true && threeSafeUp == true)
		{
			cout << "Three Safe Moving UP" << endl;
			dir = UP;
			moved = true;
		}
		else if (fruitY > y && safeDown == true && twoSafeDown == true && threeSafeDown == true)
		{
			cout << "Three Safe Moving DOWN" << endl;
			dir = DOWN;
			moved = true;
		}

	}
	if (moved == true)
	{
		update();
	}
	//TWO SAFE MOVE
	if (moved != true)
	{
		if (fruitX < x && safeLeft == true && twoSafeLeft == true)
		{
			cout << "Two Safe Moving LEFT" << endl;
			dir = LEFT;
			moved = true;
		}
		else if (fruitX > x && safeRight == true && twoSafeRight == true)
		{
			cout << "Two Safe Moving RIGHT" << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (fruitY < y && safeUp == true && twoSafeUp == true)
		{
			cout << "Two Safe Moving UP" << endl;
			dir = UP;
			moved = true;

		}
		else if (fruitY > y && safeDown == true && twoSafeDown == true)
		{
			cout << "Two Safe Moving DOWN" << endl;
			dir = DOWN;
			moved = true;
		}

	}
	if (moved == true)
	{
		update();
	}
	//SAFE MOVE
	if (moved != true)
	{
		if (fruitX < x && safeLeft == true)
		{
			cout << "Moving LEFT" << endl;
			dir = LEFT;
			moved = true;

		}
		else if (fruitX > x && safeRight == true)
		{
			cout << "Moving RIGHT" << endl;
			dir = RIGHT;
			moved = true;

		}
		else if (fruitY < y && safeUp == true)
		{
			cout << "Moving UP" << endl;
			dir = UP;
			moved = true;
		}
		else if (fruitY > y && safeDown == true)
		{
			cout << "Moving DOWN" << endl;
			dir = DOWN;
			moved = true;
		}
	}

	//DODGING
	//FOUR SAFE DODGE
	if (moved != true)
	{
		if (safeLeft == true && twoSafeLeft == true && threeSafeLeft == true && fourSafeLeft)
		{
			cout << "Four Safe Dodging LEFT" << endl;
			dir = LEFT;
			moved = true;
		}
		else if (safeRight == true && twoSafeRight == true && threeSafeRight == true && fourSafeRight)
		{
			cout << "Four Safe Dodging RIGHT" << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (safeUp == true && twoSafeUp == true && threeSafeUp == true && fourSafeUp)
		{
			cout << "Four Safe Dodging UP" << endl;
			dir = UP;
			moved = true;
		}
		else if (safeDown == true && twoSafeDown == true && threeSafeDown == true && fourSafeDown)
		{
			cout << "Four Safe Dodging DOWN" << endl;
			dir = DOWN;
			moved = true;
		}
	}
	if (moved == true)
	{
		update();
	}
	//THREE SAFE DODGE
	if (moved != true)
	{
		if (safeLeft == true && twoSafeLeft == true && threeSafeLeft == true)
		{
			cout << "Three Safe Dodging LEFT" << endl;
			dir = LEFT;
			moved = true;
		}
		else if (safeRight == true && twoSafeRight == true && threeSafeRight == true)
		{
			cout << "Three Safe Dodging RIGHT" << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (safeUp == true && twoSafeUp == true && threeSafeUp == true)
		{
			cout << "Three Safe Dodging UP" << endl;
			dir = UP;
			moved = true;
		}
		else if (safeDown == true && twoSafeDown == true && threeSafeDown == true)
		{
			cout << "Three Safe Dodging DOWN" << endl;
			dir = DOWN;
			moved = true;
		}
	}
	if (moved == true)
	{
		update();
	}
	//TWO SAFE DODGE
	if (moved != true)
	{
		if (safeLeft == true && twoSafeLeft == true)
		{
			cout << "Two Safe Dodging LEFT" << endl;
			dir = LEFT;
			moved = true;
		}
		else if (safeRight == true && twoSafeRight == true)
		{
			cout << "Two Safe Dodging RIGHT" << endl;
			dir = RIGHT;
			moved = true;
		}
		else if (safeUp == true && twoSafeUp == true)
		{
			cout << "Two Safe Dodging UP" << endl;
			dir = UP;
			moved = true;

		}
		else if (safeDown == true && twoSafeDown == true)
		{
			cout << "Two Safe Dodging DOWN" << endl;
			dir = DOWN;
			moved = true;

		}
	}
	if (moved == true)
	{
		update();
	}
	//SAFE DODGE
	if (moved != true)
	{
		if (safeLeft == true)
		{
			cout << "Dodging LEFT" << endl;
			dir = LEFT;
			moved = true;

		}
		else if (safeRight == true)
		{
			cout << "Dodging RIGHT" << endl;
			dir = RIGHT;
			moved = true;

		}
		else if (safeUp == true)
		{
			cout << "Dodging UP" << endl;
			dir = UP;
			moved = true;
		}
		else if (safeDown == true)
		{
			cout << "Dodging DOWN" << endl;
			dir = DOWN;
			moved = true;

		}
	}

	if (_kbhit())
	{
		//Translates keyboard input
		switch (_getch())
		{
		case 'x':
			gameOver = true;
			machineStage++;
			newGame = true;
			exitMachine = true; 
			cout << "Machine ended" << endl;
			system("pause");
			system("cls");
			break;
		case 'p':
			pause();
			break;
		}
	}
}