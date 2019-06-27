#ifndef game_header
#define game_header

#include <string>

class game{

public:
	game();
	void snakeSetUp();
	void fruitSetUp();
	void draw();
	void input();
	void logic();
	bool getGameOver();
	void setGameOver(std::string s);
	void setCursorPosition(int x, int y);

private:
	bool gameOver;
	const int width;
	const int height;
	int head_x = 0;
	int head_y = 0;
	int fruit_x = 0;
	int fruit_y = 0;
	int score = 0;
	int tail_length = 0;
	enum directions {STOP, LEFT, RIGHT, UP, DOWN};
	directions d; 

	int tailX[400];
	int tailY[400];
};



#endif
