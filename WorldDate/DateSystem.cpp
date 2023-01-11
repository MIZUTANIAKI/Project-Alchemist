#include "DateSystem.h"

int DateSystem::month_ = 1;
int DateSystem::day_ = 1;
bool DateSystem::changeF_ = false;

void DateSystem::Update(void)
{
	changeF_ = false;
}

void DateSystem::Init(void)
{
	month_ = 1;
	day_ = 8;
	changeF_ = true;
}

void DateSystem::Init(int month, int day)
{
	month_ = month;
	day_ = day;
	changeF_ = true;
}

bool DateSystem::NowChangeMonth(void)
{
	return changeF_;
}

int DateSystem::GetMonth(void)
{
	return month_;
}

int DateSystem::GetDay(void)
{
	return day_;
}

void DateSystem::MonthUp()
{
	if (day_ > 15)
	{
		day_ = 1;
		month_ + 1;
		if (month_ > 12)
		{
			month_ = 1;
		}
		changeF_ = true;
	}
}
