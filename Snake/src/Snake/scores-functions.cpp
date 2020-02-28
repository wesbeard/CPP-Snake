#include "snake.h"

void Snake::loadHighScores()
{
	int i;
	int tempScore;
	string trash;
	ifstream fin;
	fin.open(SCORES_FILE);

	for (i = 0; i < 10; i++)
	{
		fin >> highScores[i];
	}
	sortHighScores();
}

void Snake::sortHighScores()
{
	int i, j;
	int temp;
	bool sorted = false;

	while (sorted == false)
	{
		for (j = 0; j < 10; j++)
		{
			for (i = 0; i < 10; i++)
			{

				if (highScores[i] < highScores[i + 1])
				{
					temp = highScores[i + 1];
					highScores[i + 1] = highScores[i];
					highScores[i] = temp;
				}
			}
		}
		sorted = true;
	}
}

void Snake::displayHighScores()
{
	system("cls");
	int i;
	cout << "=================" << endl
		<< "|| HIGH SCORES ||" << endl
		<< "=================" << endl;
	for (i = 0; i < 10; i++)
	{
		cout << right << setw(2) << i + 1 << ". " << highScores[i] << endl;
	}
	system("pause");
	system("cls");
}

void Snake::updateHighScores(int score)
{
	loadHighScores();
	int i;
	ofstream fout;
	fout.open(SCORES_FILE);

	if (score > highScores[9])
	{
		highScores[9] = score;
	}

	sortHighScores();

	for (i = 0; i < 10; i++)
	{
		fout << highScores[i] << endl;
	}
}