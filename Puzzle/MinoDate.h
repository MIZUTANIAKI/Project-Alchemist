#pragma once
#include <array>
#include <string>
#include "EnumTypeList.h"
#include "MinoTemplate.h"


class MinoDate
{
public:
	MinoDate();
	~MinoDate();

	void InitTemplateDateList(void);

	TemplateDate GetMinoTemplate(MinoTemplate mino);
	std::vector<std::vector<bool>> GetMino(TemplateDate date, int dir);
private:
	void InitTemplatePosDate(int num, int x, int y);
	void SetMinoPosDate(int num, int fx, int fy, std::string filenum);

	std::vector<std::vector<bool>> NormalMino(TemplateDate date);
	std::vector<std::vector<bool>> VerticalMino(TemplateDate date);
	std::vector<std::vector<bool>> ReversallMino(TemplateDate date);
	std::vector<std::vector<bool>> ReversallVerticalMino(TemplateDate date);

	std::array < TemplateDate, size_t(MinoTemplate::Max)> templateDateList_;
};

