#include "snake.h"

int main()
{
	Snake snake;
	int menuChoice;
	bool validChoice = false;
	bool quit = false;

	snake.hideCursor();

	while (validChoice == false && quit == false)
	{
		menuChoice = 0;
		snake.exitMachine = false;
		snake.machineStage = 0;

		cout << "  _____             _____             _           " << endl
			<< " / ____|_     _    / ___*|~~         | |           " << endl
			<< "| |   _| |_ _| |_ | (___  _ __   __ _| | _____     " << endl
			<< "| |  |_   _|_   _| \\___ \\|  _ \\ / _  | |/ / _ \\" << endl
			<< "| |____|_|   |_|   ____) | | | | (_| |   <  __/    " << endl
			<< " \\_____|          |_____/|_| |_|\\__,_|_|\\_\\___|" << endl
			<< "==============================================="     << endl
			<< "|| [1] Play Snake                            ||"     << endl
			<< "|| [2] Let the Machine Play                  ||"     << endl
			<< "|| [3] Incremental Machine Learning          ||"     << endl
			<< "|| [4] View High Scores                      ||"     << endl
			<< "|| [5] Quit                                  ||"     << endl
			<< "==============================================="     << endl;
		cin >> menuChoice;
		if (menuChoice <= 5 && menuChoice >= 0)
		{
			switch (menuChoice)
			{
			case 1:
				snake.setup();
				while (!snake.gameOver)
				{
					Sleep(72);
					snake.draw();
					snake.input();
					snake.logic();
				}
				break;
			case 2:
				snake.setup();
				while (!snake.gameOver)
				{
					Sleep(36);
					snake.draw();
					snake.machineMove();
					snake.logic();
				}
				break;
			case 3:
				snake.setup();
				snake.machineStage++;
				while (snake.exitMachine == false)
				{
					if (snake.newGame == true)
					{
						snake.setup();
					}
					if (snake.machineStage == 1)
					{
						Sleep(72);
						snake.newGame = false;
						snake.draw();
						snake.firstMachine();
						snake.logic();
					}
					else if (snake.machineStage == 2)
					{
						Sleep(72);
						snake.newGame = false;
						snake.draw();
						snake.secondMachine();
						snake.logic();
					}
					else if (snake.machineStage == 3)
					{
						Sleep(72);
						snake.newGame = false;
						snake.draw();
						snake.thirdMachine();
						snake.logic();
					}
					else if (snake.machineStage == 4)
					{
						Sleep(72);
						snake.newGame = false;
						snake.draw();
						snake.fourthMachine();
						snake.logic();
					}
					else
					{
						break;
					}
				}
				break;
			case 4:
				snake.loadHighScores();
				snake.displayHighScores();
				break;
			case 5:
				cout << "Thanks for playing!" << endl;
				Sleep(1000);
				quit = true;
				break;
			default:
				validChoice = false;
				cout << "Please enter a valid menu selection" << endl;
				break;
			}
		
		}
		else
		{
			validChoice = false;
			cout << "Please enter a valid menu selection" << endl;
		}
	}
}