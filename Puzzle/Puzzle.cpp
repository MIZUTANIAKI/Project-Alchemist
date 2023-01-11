#include <DxLib.h>
#include "Puzzle.h"


Puzzle::Puzzle()
{
}

Puzzle::~Puzzle()
{
}

void Puzzle::Init(int x, int y)
{
	DATEDATA date;
	DxLib::GetDateTime(&date);
	SRand(date.Year + date.Mon + date.Day + date.Hour + date.Min + date.Sec);
	srand(GetRand(rand()));
	srand(GetRand(rand()));

	if (x < 6)
	{
		x = 6;
	}
	if (y < 6)
	{
		y = 6;
	}

	PosDate nonePosDate;
	nonePosDate.dispFlag = false;
	nonePosDate.color = Color::None;
	nonePosDate.point = 0;
	nonePosDate.id = -1;

	int chainGH = LoadGraph("chain.png", true);

	puzzlefield.resize(MAPSIZEX);
	for (int x = 0; x < MAPSIZEX; x++)
	{
		for (int y = 0; y < MAPSIZEY; y++)
		{
			puzzlefield[x].emplace_back(nonePosDate);
		}
	}

	puzzleMode_ = PuzzleMode::none;
	nextColor_ = Color::Blue;
	monoDate_ = std::make_unique<MinoDate>();
	monoDate_->InitTemplateDateList();

	pasteMino_.clear();
	grabMino_.clear();
}

int Puzzle::GetAstrogicalBonus(Color color)
{
	Astrogical now = ConstellationSystem::GetConstellation();

	switch (now)
	{
	case Astrogical::Yagiza:
		break;
	case Astrogical::Mizugameza:
		break;
	case Astrogical::Uoza:
		break;
	case Astrogical::Ohituziza:
		break;
	case Astrogical::Ousiza:
		break;
	case Astrogical::Futagoza:
		break;
	case Astrogical::Kaniza:
		break;
	case Astrogical::Sisiza:
		break;
	case Astrogical::Otomeza:
		break;
	case Astrogical::Tenbinza:
		break;
	case Astrogical::Sasoriza:
		break;
	case Astrogical::Iteza:
		break;
	case Astrogical::Max:
		break;
	default:
		break;
	}
	return 0;
}

bool Puzzle::SetPoint(int x, int y, std::vector<Vector2>& vec)
{
	if (x < 0)return false;
	if (x >= MAPSIZEX)return false;
	if (y < 0)return false;
	if (y >= MAPSIZEY)return false;
	if (puzzlefield[x][y].dispFlag)return false;
	for (const auto& pos : vec)
	{
		if (pos.x == x && pos.y == y)
		{
			return false;
		}
	}
	return true;
}

std::vector<Vector2> Puzzle::PointFix(int x, int y, std::vector<Vector2>& vec)
{
	if (SetPoint(x - 1, y, vec))
	{
		puzzlefield[x - 1][y].point += 1;
		vec.emplace_back(Vector2(x - 1, y));
	}
	if (SetPoint(x + 1, y, vec))
	{
		puzzlefield[x + 1][y].point += 1;
		vec.emplace_back(Vector2(x + 1, y));
	}
	if (SetPoint(x, y - 1, vec))
	{
		puzzlefield[x][y - 1].point += 1;
		vec.emplace_back(Vector2(x, y - 1));
	}
	if (SetPoint(x, y + 1, vec))
	{
		puzzlefield[x][y + 1].point += 1;
		vec.emplace_back(Vector2(x, y + 1));
	}
	if (SetPoint(x - 1, y - 1, vec))
	{
		puzzlefield[x - 1][y - 1].point += 1;
		vec.emplace_back(Vector2(x - 1, y - 1));
	}
	if (SetPoint(x + 1, y - 1, vec))
	{
		puzzlefield[x + 1][y - 1].point += 1;
		vec.emplace_back(Vector2(x + 1, y - 1));
	}
	if (SetPoint(x - 1, y + 1, vec))
	{
		puzzlefield[x - 1][y + 1].point += 1;
		vec.emplace_back(Vector2(x - 1, y + 1));
	}
	if (SetPoint(x + 1, y + 1, vec))
	{
		puzzlefield[x + 1][y + 1].point += 1;
		vec.emplace_back(Vector2(x + 1, y + 1));
	}
	return vec;
}

void Puzzle::DellPuzzleFieldDate(int id)
{
	for (int x = 0; x < MAPSIZEX; x++)
	{
		for (int y = 0; y < MAPSIZEY; y++)
		{
			if (puzzlefield[x][y].id == id)
			{
				puzzlefield[x][y].dispFlag = false;
				puzzlefield[x][y].color = Color::None;
				puzzlefield[x][y].point = 0;
				puzzlefield[x][y].id = -1;
			}
		}
	}
}

int Puzzle::GetColor(Color color)
{
	switch (color)
	{
	case Color::None:
		return -1;
		break;
	case Color::Red:
		return 0xff0000;
		break;
	case Color::Green:
		return 0x00ff00;
		break;
	case Color::Blue:
		return 0x0000ff;
		break;
	case Color::Yellow:
		return 0xbdb76b;
		break;
	case Color::Purple:
		return 0xC030C0;
		break;
	case Color::White:
		return 0x808080;
		break;
	default:
		break;
	}
	return -1;
}
