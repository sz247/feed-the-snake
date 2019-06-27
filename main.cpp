#include "Game.h"
#include <windows.h>

int main() {

	game g;
	g.snakeSetUp();
	g.fruitSetUp();
	system("cls"); 
	while (!g.getGameOver()) {
		g.draw();
		g.input();
		g.logic();
		Sleep(500);
	}
	
}