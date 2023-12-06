#pragma once

#include <iostream>
#include <string>

#include "Material.hpp"

class Board
{
public:
	Material m_Board[8][8]
	{
		{ Material(2, Tower), Material(2, Knight), Material(2, Bishop), Material(2, King), Material(2, Queen), Material(2, Bishop), Material(2, Knight), Material(2, Tower)},
		{ Material(2, Pon), Material(2, Pon), Material(2, Pon), Material(2, Pon), Material(2, Pon), Material(2, Pon), Material(2, Pon), Material(2, Pon) },
		{ Material(), Material(), Material(),Material(),Material(),Material(),Material(),Material() },
		{ Material(), Material(), Material(),Material(),Material(),Material(),Material(),Material() },
		{ Material(), Material(), Material(),Material(),Material(),Material(),Material(),Material() },
		{ Material(), Material(), Material(),Material(),Material(),Material(),Material(),Material() },
		{ Material(1, Pon), Material(1, Pon), Material(1, Pon), Material(1, Pon), Material(1, Pon), Material(1, Pon), Material(1, Pon), Material(1, Pon) },
		{ Material(1, Tower), Material(1, Knight), Material(1, Bishop), Material(1, King), Material(1, Queen), Material(1, Bishop), Material(1, Knight), Material(1, Tower)},
	};

	Board() {}

	void PrintBoard()
	{
		for (int i = 0; i < 8; i++)
		{
			std::cout << m_BoardNumbers[i] << " ";

			for (int j = 0; j < 8; j++)
			{
				if (m_Board[i][j].GetPlayer() == 1)
					printf("\x1B[35m");
				else if (m_Board[i][j].GetPlayer() == 2)
					printf("\x1B[36m");
				else
					printf("\x1B[31m");

				std::cout << m_Board[i][j].ToChar() << " ";
				printf("\033[0m");
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

	char* GetBoardLowerAlpha()
	{
		return m_BoardLowerAlpha;
	}

	char* GetBoardNumbers()
	{
		return m_BoardNumbers;
	}

	Material GetMaterialPoint(std::string input)
	{
		std::pair<int, int> boardPos = GetBoardPositionFromPI(input);
		return m_Board[boardPos.second][boardPos.first];
	}

	bool Move(Material* selectedMat, std::string origin, std::string location)
	{
		std::pair<int, int> originPos = GetBoardPositionFromPI(origin);
		std::pair<int, int> boardPos = GetBoardPositionFromPI(location);

		if (selectedMat->ValidMove(originPos, boardPos, m_Board))
		{
			selectedMat->MoveIncrease();
			m_Board[originPos.second][originPos.first] = Material();
			m_Board[boardPos.second][boardPos.first] = *selectedMat;
			return true;
		}

		return false;
	}
private:
	std::pair<int, int> GetBoardPositionFromPI(std::string input)
	{
		std::pair<int, int> result;

		char coords[3];
		strcpy_s(coords, input.c_str());

		switch (coords[0])
		{
		case 'A':
		case 'a':
			result.first = 0;
			break;
		case 'B':
		case 'b':
			result.first = 1;
			break;
		case 'C':
		case 'c':
			result.first = 2;
			break;
		case 'D':
		case 'd':
			result.first = 3;
			break;
		case 'E':
		case 'e':
			result.first = 4;
			break;
		case 'F':
		case 'f':
			result.first = 5;
			break;
		case 'G':
		case 'g':
			result.first = 6;
			break;
		case 'H':
		case 'h':
			result.first = 7;
			break;
		default:
			break;
		}

		switch (coords[1])
		{
		case '1':
			result.second = 0;
			break;
		case '2':
			result.second = 1;
			break;
		case '3':
			result.second = 2;
			break;
		case '4':
			result.second = 3;
			break;
		case '5':
			result.second = 4;
			break;
		case '6':
			result.second = 5;
			break;
		case '7':
			result.second = 6;
			break;
		case '8':
			result.second = 7;
			break;
		default:
			break;
		}

		return result;
	}

	char m_BoardNumbers[8]{ '1', '2', '3', '4', '5', '6', '7', '8' };
	char m_BoardAlpha[8]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	char m_BoardLowerAlpha[8]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
};