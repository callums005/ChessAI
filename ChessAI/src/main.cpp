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
			std::cout << m_BoardNumbers[i] << " ";

			for (int j = 0; j < 8; j++)
			{
				std::cout << m_Board[i][j] << " ";
			}

			std::cout << std::endl;
		}

		std::cout << "  ";

		for (int k = 0; k < 8; k++)
		{
			std::cout << m_BoardAlpha[k] << " ";
		}

		std::cout << std::endl;
	}

	char* GetBoardAlpha()
	{
		return m_BoardAlpha;
	}

	char* GetBoardNumbers()
	{
		return m_BoardNumbers;
	}

private:
	char m_Board[8][8]
	{
		{ 'T', 'H', 'B', 'K', 'Q', 'B', 'H', 'T'},
		{ 'i', 'i', 'i', 'i', 'i', 'i', 'i', 'i'},
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{ 'i', 'i', 'i', 'i', 'i', 'i', 'i', 'i'},
		{ 'T', 'H', 'B', 'K', 'Q', 'B', 'H', 'T'}
	};

	char m_BoardNumbers[8]{ '1', '2', '3', '4', '5', '6', '7', '8' };
	char m_BoardAlpha[8]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
};

bool ValidateInput(std::string value, int min, int max, Board* board)
{
	
	if (value.length() > max || value.length() < min)
	{
		std::cout << "Bad input length." << std::endl;
		return false;
	}

	char coords[3];
	strcpy_s(coords, value.c_str());

	char* alpha = board->GetBoardAlpha();
	char* numbers = board->GetBoardNumbers();
	bool ac = false;
	bool nc = false;

	for (int i = 0; i < 8; i++)
	{
		if (coords[0] == alpha[i])
		{
			ac = true;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		if (coords[1] == numbers[i])
		{
			nc = true;
		}
	}

	if (!ac || !nc)
		return false;

	return true;
}

int main(int argc, char* argv)
{
	Board board;
	
	board.PrintBoard();

	std::string input;

	while (input != "exit")
	{
		std::cin >> input;

		while (!ValidateInput(input, 2, 2, &board))
		{
			std::cout << "Invalid Board Place\n";
			std::cin >> input;
		}

		std::cout << input << std::endl;
	}
}