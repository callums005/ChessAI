#include <iostream>
#include <string>
#include <Windows.h>

#include "Board.hpp"
#include "Material.hpp"

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
	char* lAlpha = board->GetBoardLowerAlpha();
	char* numbers = board->GetBoardNumbers();
	bool ac = false;
	bool nc = false;

	for (int i = 0; i < 8; i++)
		if (coords[0] == alpha[i])
			ac = true;

	for (int i = 0; i < 8; i++)
		if (coords[0] == lAlpha[i])
			ac = true;

	for (int i = 0; i < 8; i++)
		if (coords[1] == numbers[i])
			nc = true;

	if (!ac || !nc)
		return false;

	return true;
}

bool SelectPiece(std::string& input, Board* board, Material& selectedMat, int turn)
{
	std::cout << "Select Piece (Format: A1/a1): ";
	std::cin >> input;

	if (input == "exit")
		return true;

	while (!ValidateInput(input, 2, 2, board))
	{
		std::cout << "Invalid Board Place\n";
		std::cin >> input;

		if (input == "exit")
			return true;
	}

	selectedMat = board->GetMaterialPoint(input);

	while (selectedMat.GetPlayer() != turn)
	{
		std::cout << "You cannot move another players piece. Try again." << std::endl;
		std::cout << "Select Piece (Format: A1/a1): ";
		std::cin >> input;

		if (input == "exit")
			return true;

		while (!ValidateInput(input, 2, 2, board))
		{
			std::cout << "Invalid Board Place\n";
			std::cin >> input;

			if (input == "exit")
				return true;

		}

		selectedMat = board->GetMaterialPoint(input);
	}

	return false;
}

bool SelectMove(std::string& input, Board* board, Material& selected)
{
	std::string origin = input;

	std::cout << "Select Location (Format: A1/a1): ";
	std::cin >> input;

	if (input == "exit")
		return true;

	while (!ValidateInput(input, 2, 2, board))
	{
		std::cout << "Invalid Board Place\n";
		std::cin >> input;

		if (input == "exit")
			return true;
	}

	while (!board->Move(&selected, origin, input))
	{
		std::cout << "Invalid Move. Try again" << std::endl;

		std::cout << "Select Location (Format: A1/a1): ";
		std::cin >> input;

		if (input == "exit")
			return true;

		while (!ValidateInput(input, 2, 2, board))
		{
			std::cout << "Invalid Board Place\n";
			std::cin >> input;

			if (input == "exit")
				return true;
		}
	}

	return false;
}

int main(int argc, char* argv)
{
	int turn = 1;
	Board board;
	std::string input;

	while (input != "exit")
	{
		// Clears the screen
		std::cout << "\x1B[2J\x1B[H";

		board.PrintBoard();
		Material selectMat;
		
		bool shoudExit = SelectPiece(input, &board, selectMat, turn);

		if (shoudExit)
			return 0;

		shoudExit = SelectMove(input, &board, selectMat);

		if (shoudExit)
			return 0;

		//turn = turn == 1 ? 2 : 1;
	}
}