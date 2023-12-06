#pragma once

enum MaterialType
{
	None,
	Pon,
	Tower,
	Knight,
	Bishop,
	King,
	Queen
};

struct Material
{
	Material()
		: m_Player(-1), m_Piece(None)
	{}

	Material(int player, MaterialType piece)
		: m_Player(player), m_Piece(piece)
	{}


	int GetPlayer()
	{
		return m_Player;
	}

	MaterialType GetType()
	{
		return m_Piece;
	}

	char ToChar()
	{
		switch (m_Piece)
		{
		case Pon:
			return 'i';
		case Tower:
			return 'T';
		case Knight:
			return 'H';
		case Bishop:
			return 'B';
		case King:
			return 'K';
		case Queen:
			return 'Q';
;		default:
			return ' ';
		}
	}

	bool ValidMove(std::pair<int, int> origin, std::pair<int, int> newLocation, Material board[8][8])
	{
		switch (m_Piece)
		{
		case None:
			break;
		case Pon:
			if (m_Player == 1)
			{
				if (origin.first == newLocation.first)
				{
					// Can only move forward (2 if first move)
					if (m_MoveCount > 0)
					{
						// Only forward 1
						if (origin.second - newLocation.second == 1)
						{
							if (board[newLocation.second][newLocation.first].GetType() == None)
								return true;
							else
								return false;
						}
					}
					else
					{
						// Only forward < 2
						if (origin.second - newLocation.second >= 1 && origin.second - newLocation.second <= 2)
						{
							if (board[newLocation.second][newLocation.first].GetType() == None)
								return true;
							else
								return false;
						}
					}
				}
				else if (origin.second - newLocation.second == 1 && origin.first - newLocation.first == -1)
				{
					if (board[newLocation.second][newLocation.first].GetType() != None)
						return true;
					else
						return false;
				}
				else if (origin.second - newLocation.second == 1 && origin.first - newLocation.first == 1)
				{
					if (board[newLocation.second][newLocation.first].GetType() != None)
						return true;
					else
						return false;
				}
			}
			else if (m_Player == 2)
			{

			}
			break;
		case Tower:
			break;
		case Knight:
			break;
		case Bishop:
			break;
		case King:
			break;
		case Queen:
			break;
		default:
			break;
		}


		return false;
	}

	void MoveIncrease()
	{
		m_MoveCount++;
	}

private:
	int m_Player;
	MaterialType m_Piece;

	int m_MoveCount = 0;
};