#include "snake.h" 

void Snake::setup()
{
	gameOver = false;
	//stops snake when game is launched
	dir = STOP;
	//sets snake position to middle
	x = (WIDTH * 2) / 2;
	y = HEIGHT / 2;
	//randomizes fruit position
	srand(time(NULL));
	nTail = 0;
	fruitX = 2;
	fruitY = rand() % HEIGHT;
	score = 0;
	system("cls");
}

void Snake::draw()
{
	int i;
	int j;
	int k;
	clearScreen();

	//Displays top border
	for (i = 0; i < WIDTH + 1; i++)
	{
		cout << "# ";
	}
	cout << " [(" << score << ")]";
	cout << endl;
	//Displays walls
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < (WIDTH * 2); j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			//Prints snake head
			if (i == y && j == x)
			{
				cout << "Q";
			}
			//Prints fruit
			else if (i == fruitY && j == fruitX)
			{
				cout << "X";
			}
			//Prints tail
			else
			{
				bool print = false;
				for (k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
				{
					cout << " ";
				}
			}
			if (j == ((WIDTH * 2) - 1))
			{
				cout << "#";
			}
		}
		cout << endl;
	}
	//Displays bottom border
	for (i = 0; i < WIDTH + 1; i++)
	{
		cout << "# ";
	}

	cout << endl;
	cout << "[P] Pause" << endl;
	cout << "[X] Exit" << endl;
	
	if (machineStage > 0)
	{
		switch (machineStage)
		{
		case 1:
			cout << "STAGE 1" << endl;
			break;
		case 2:
			cout << "STAGE 2" << endl;
			break;
		case 3:
			cout << "STAGE 3" << endl;
			break;
		case 4:
			cout << "STAGE 4" << endl;
			break;
		}
	}
	cout << "Snake pos: " << setfill(' ') << setw(2) << (x /2) << ", " << setw(2) << y << endl;
}

void Snake::input()
{
	if (_kbhit())
	{
		//Translates keyboard input
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			currentDir = "LEFT";
			break;
		case 'd':
			dir = RIGHT;
			currentDir = "RIGHT";
			break;
		case 'w':
			dir = UP;
			currentDir = "UP";
			break;
		case 's':
			currentDir = "DOWN";
			dir = DOWN;
			break;
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

void Snake::logic()
{
	int i;
	bool validFruit = false;

	//Tail information
	prevX = tailX[0];
	prevY = tailY[0];
	tailX[0] = x;
	tailY[0] = y;

	for (i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	//Changes direction
	switch (dir)
	{
	case Snake::LEFT:
		if (dir != RIGHT || nTail == 0)
		{
			x -= 2;
		}
		break;
	case Snake::RIGHT:
		if (dir != LEFT || nTail == 0)
		{
			x += 2;
		}
		break;
	case Snake::UP:
		if (dir != DOWN || nTail == 0)
		{
			y--;
		}
		break;
	case Snake::DOWN:
		if (dir != UP || nTail == 0)
		{
			y++;
		}
		break;
	default:
		break;
	}

	//Checks if snake touches a fruit
	if (x == fruitX && y == fruitY)
	{
		score++;
		nTail++;

		//Places a new fruit randomly
		while (validFruit == false)
		{
			do
			{
				fruitX = rand() % ((WIDTH * 2) - 1);
			} while (fruitX % 2 != 0);
			fruitY = rand() % HEIGHT;

			for (i = 0; i < nTail; i++)
			{
				if (tailX[i] != fruitX && tailY[i] != fruitY)
				{
					validFruit = true;
				}
			}
		}
	}

	//Checks if snake hits a wall
	if (x > ((WIDTH * 2) - 1) || x < 0 || y > (HEIGHT - 1) || y < 0)
	{
		if (machineStage < 5)
		{
			machineStage++;
			newGame = true;
		}
		else
		{
			exitMachine = true;
		}
		clearScreen();
		cout << "You hit a wall!" << endl;
		system("pause");
		gameOver = true;
		updateHighScores(score);
		system("cls");
	}

	//Checks if snake hits its tail
	for (i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			if (machineStage < 5)
			{
				machineStage++;
				newGame = true;
			}
			else
			{
				exitMachine = true;
			}
			clearScreen();
			cout << "You hit your tail!" << endl;
			system("pause");
			gameOver = true;
			updateHighScores(score);
			system("cls");
		}
	}
}

void Snake::update()
{
	int i;
	bool validFruit = false;

	//Checks if snake touches a fruit
	if (x == fruitX && y == fruitY)
	{
		system("cls");
		score++;
		nTail++;

		//Places a new fruit randomly
		while (validFruit == false)
		{
			do
			{
				fruitX = rand() % ((WIDTH * 2) - 1);
			} while (fruitX % 2 != 0);
			fruitY = rand() % HEIGHT;

			for (i = 0; i < nTail; i++)
			{
				if (tailX[i] != fruitX && tailY[i] != fruitY)
				{
					validFruit = true;
				}
			}
		}
	}
}

void Snake::pause()
{
	cout << "Game Paused..." << endl;
	system("pause");
}

void Snake::hideCursor()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Snake::clearScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}