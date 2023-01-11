#include <iostream>
#include <fstream>
#include <sstream>
#include "MinoDate.h"
#include<windows.h>

template < typename T > std::string to_string(const T& n)
{
	std::ostringstream stm;
	stm << n;
	return stm.str();
}

MinoDate::MinoDate()
{
}

MinoDate::~MinoDate()
{
}

void MinoDate::InitTemplateDateList(void)
{
	std::string filename("date/setting/setting00.txt");
	int inputNum;
	std::ifstream input_file(filename);
	if (!input_file.is_open())
	{
		std::string errormes = "ERROR File not found.\n..>";
		errormes += "BlockSettingFile";
		MessageBox(
			NULL,
			TEXT(errormes.c_str()),
			TEXT("ERROR File"),
			MB_OK | MB_ICONINFORMATION);
	}
	int tcon = 0;
	int ty;
	while (input_file >> inputNum)
	{
		if (tcon % 2 == 0)
		{
			ty = inputNum;
		}
		else
		{
			InitTemplatePosDate(tcon / 2, inputNum, ty);
			SetMinoPosDate(tcon / 2, inputNum, ty, to_string(tcon / 2));
		}
		tcon++;
	}
}

TemplateDate MinoDate::GetMinoTemplate(MinoTemplate mino)
{
	for (auto date : templateDateList_)
	{
		if (date.mino == mino)
		{
			return date;
		}
	}
	return TemplateDate();
}

std::vector<std::vector<bool>> MinoDate::GetMino(TemplateDate date, int dir)
{
	if (dir >= 4 || dir < 0)
	{
		return std::vector<std::vector<bool>>();
	}
	if (dir == 0)
	{
		return NormalMino(date);
	}
	if (dir == 1)
	{
		return VerticalMino(date);
	}
	if (dir == 2)
	{
		return ReversallMino(date);
	}
	if (dir == 3)
	{
		return ReversallVerticalMino(date);
	}
	return std::vector<std::vector<bool>>();
}

void MinoDate::InitTemplatePosDate(int num, int x, int y)
{
	templateDateList_[num].mino = static_cast<MinoTemplate>(num);
	templateDateList_[num].pos.resize(y);
	for (int tmpy = 0; tmpy < y; tmpy++)
	{
		templateDateList_[num].pos[tmpy].resize(x);
	}
}

void MinoDate::SetMinoPosDate(int num, int fx, int fy, std::string filenum)
{
	std::string filename("date/bdate/" + filenum + ".txt");
	int inputNum;

	std::ifstream input_file(filename);
	if (!input_file.is_open())
	{
		std::string errormes = "ERROR File not found.>";
		errormes += ":f:";
		MessageBox(
			NULL,
			TEXT(errormes.c_str()),
			TEXT("ERROR File"),
			MB_OK | MB_ICONINFORMATION);
	}
	int tcon = 0;
	while (input_file >> inputNum)
	{
		templateDateList_[num].pos[tcon / fx % fy][tcon % fx] = inputNum;
		tcon++;
	}
}

std::vector<std::vector<bool>> MinoDate::NormalMino(TemplateDate date)
{
	return date.pos;
}

std::vector<std::vector<bool>> MinoDate::VerticalMino(TemplateDate date)
{
	std::vector<std::vector<bool>> rtnVec;
	rtnVec.resize(date.pos[0].size());
	for (int y = 0; y < date.pos[0].size(); y++)
	{
		rtnVec[y].resize(date.pos.size());
		for (int x = 0; x < date.pos.size(); x++)
		{
			rtnVec[y][x] = date.pos[date.pos.size() - 1 - x][y % date.pos[0].size()];
		}
	}
	return rtnVec;
}

std::vector<std::vector<bool>> MinoDate::ReversallMino(TemplateDate date)
{
	std::vector<std::vector<bool>> rtnVec;
	rtnVec.resize(date.pos.size());
	for (int y = 0; y < date.pos.size(); y++)
	{
		rtnVec[y].resize(date.pos[0].size());
		for (int x = 0; x < date.pos[0].size(); x++)
		{
			rtnVec[y][x] = date.pos[date.pos.size() - 1 - y][date.pos[0].size() - 1 - x];
		}
	}
	return rtnVec;
}

std::vector<std::vector<bool>> MinoDate::ReversallVerticalMino(TemplateDate date)
{
	std::vector<std::vector<bool>> rtnVec;
	rtnVec.resize(date.pos[0].size());
	for (int y = 0; y < date.pos[0].size(); y++)
	{
		rtnVec[y].resize(date.pos.size());
		for (int x = 0; x < date.pos.size(); x++)
		{
			rtnVec[y][x] = date.pos[x][date.pos[0].size() - 1 - y];
		}
	}
	return rtnVec;
}
