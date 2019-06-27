#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <ctime>
#include "Game.h"

game::game() : width(20), height(20) {
	gameOver = false; 
	head_x = 0;
	head_y = 0;
	fruit_x = 0;
	fruit_y = 0;
	score = 0;
	tail_length = 0; 
}

void game::snakeSetUp() {
	d = STOP;
	head_x = (int)floor(width/2);
	head_y = (int)floor(height/2); 
}

void game::fruitSetUp() {
	srand(time(0));
	fruit_x = rand() % 20; 
	fruit_y = rand() % 20;
}

bool game::getGameOver() {
	return gameOver;
}
void game::setGameOver(std::string s) {
	system("cls");
	//setCursorPosition(0, 0);
	for (int i = 0; i < 20; i++) {
		std::cout << '#';
	}
	std::cout << std::endl;
	std::cout << s << std::endl;
	std::cout << "Your score was: " << score << std::endl; 
	for (int i = 0; i < 29; i++) {
		std::cout << '#';
	}
	std::cout << std::endl;

	gameOver = true;
}


void game::draw() {
	//system("cls");
	setCursorPosition(0, 0);
	for (int i = 0; i < 23; i++) {
		std::cout << '#';
	}
	std::cout << std::endl;

	for (int i = 0; i < 21; i++) {
		std::cout << "#";
		for (int j = 0; j < 21; j++) {
			//print head
			if (head_x == i && head_y == j) {
				std::cout << 'O';
			}
			//print fruit
			else if (fruit_x == i && fruit_y == j){
				std::cout << 'F';
			} 
			else {
				bool empty = true; 
				for (int t = 0; t < tail_length; t++) {
					if (tailX[t] == i && tailY[t] == j) {
						std::cout << 'o';
						empty = false; 
					}
				}
				if (empty == true) {
					std::cout << ' ';
				}
				
			}

		}
		std::cout << '#' << std::endl;
	}

	for (int i = 0; i < 23; i++) {
		std::cout << '#';
	}
	std::cout << std::endl;
	std::cout << "Score: " << score << std::endl; 

}

void game::input() {
	char c; 
	if (_kbhit()) {
		c = _getch();
		if (c == 'a') {
			d = LEFT;
		}
		else if (c == 'd') {
			d = RIGHT; 
		}
		else if (c == 'w') {
			d = UP; 
		}
		else if (c == 's') {
			d = DOWN;
		}
		else if (c == 'x') {
			setGameOver("You pressed x: Game Over!!!");
		}
	}

}

void game::logic() {

	for (int i = tail_length - 1; i > 0; i--) {
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];
	}
	tailX[0] = head_x;
	tailY[0] = head_y;


	if (d == LEFT) {
		--head_y; 
	}
	else if (d == RIGHT) {
		++head_y;
	}
	else if (d == UP) {
		--head_x;
	}
	else if (d == DOWN) {
		++head_x;
	}

	if (head_x < 0) {
		head_x = 19; 
	}
	else if (head_x > 19) {
		head_x = 0;
	}
	else if (head_y < 0) {
		head_y = 19;
	}
	else if (head_y > 19) {
		head_y = 0;
	}

	for (int t = 0; t < tail_length; t++) {
		if (head_x == tailX[t] && head_y == tailY[t]) {
			setGameOver("The snake is kiiled: Game Over!!!");
		}
	}

	if (head_x == fruit_x && head_y == fruit_y) {
		score += 10; 
		fruitSetUp();

		++tail_length;
	}
}



void game::setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}