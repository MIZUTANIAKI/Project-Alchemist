#include "SeasonSystem.h"
#include "DateSystem.h"

SeasonSystem::FourSeason SeasonSystem::season_ = FourSeason::Autumn;

void SeasonSystem::Update(void)
{
	if (DateSystem::NowChangeMonth())
	{
		SetNextSeason();
	}
}

void SeasonSystem::Init(void)
{
	SetNextSeason();
}

SeasonSystem::FourSeason SeasonSystem::GetSeason(void)
{
	return season_;
}

void SeasonSystem::SetNextSeason(void)
{
	if (static_cast<FourSeason>(DateSystem::GetMonth() / 4) == FourSeason::Max)
	{
		season_ = FourSeason::Spring;
	}

	season_ = static_cast<FourSeason>(DateSystem::GetMonth() / 4);
}
