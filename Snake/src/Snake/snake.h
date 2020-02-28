#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

const string SCORES_FILE = "highscores.txt";

class Snake
{
public:
	bool gameOver;
	int x, y, fruitX, fruitY, score;
	string currentDir = "STOP";
	int prevX, prevY;
	int prev2X, prev2Y;
	int tailX[100], tailY[100];
	int nTail = 0;
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection dir;
	const int WIDTH = 20;
	const int HEIGHT = 20;
	int highScores[10];
	int machineStage = 0;
	bool newGame = false;
	bool exitMachine = false;

	//Game functions
	void setup();
	void draw();
	void input();
	void logic();
	void update();
	void pause();
	void hideCursor();
	void clearScreen();

	//Machine functions
	void machineMove();
	void firstMachine();
	void secondMachine();
	void thirdMachine();
	void fourthMachine();

	//Scores functions
	void loadHighScores();
	void sortHighScores();
	void updateHighScores(int score);
	void displayHighScores();
};