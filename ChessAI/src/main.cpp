#include <iostream>
#include <string>

class Board
{
public:
	Board() {}

	void PrintBoard()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				std::cout << board[i][j];
			}

			std::cout << std::endl;
		}
	}

private:
	char board[8][8]
	{
		{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
		{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
		{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
		{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
		{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
		{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
		{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
		{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}
	};
};

int main(int argc, char* argv)
{
	Board board;

	board.PrintBoard();
}