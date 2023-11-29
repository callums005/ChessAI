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

private:
	int m_Player;
	MaterialType m_Piece;
};