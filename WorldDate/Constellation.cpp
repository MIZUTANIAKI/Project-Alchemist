#include "Constellation.h"
#include "DateSystem.h"

ConstellationSystem::Constellation ConstellationSystem::constellation_ = Constellation::Mizugameza;

void ConstellationSystem::Update(void)
{
	if (DateSystem::NowChangeMonth())
	{
		SetNextConstellation();
	}
}

void ConstellationSystem::Init(void)
{
	SetNextConstellation();
}

ConstellationSystem::Constellation ConstellationSystem::GetConstellation(void)
{
	return constellation_;
}

void ConstellationSystem::SetNextConstellation(void)
{
	if (static_cast<Constellation>(DateSystem::GetMonth()) == Constellation::Max)
	{
		constellation_ = Constellation::Mizugameza;
	}

	constellation_ = static_cast<Constellation>(DateSystem::GetMonth());
}
