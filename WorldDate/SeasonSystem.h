#pragma once

class SeasonSystem
{
public:
	void Update(void);
	void Init(void);

	/// <summary>
	/// ãGêﬂ
	/// </summary>
	enum FourSeason
	{
		Spring,
		Summer,
		Autumn,
		Winter,
		Max
	};

	static FourSeason GetSeason(void);
private:
	void SetNextSeason(void);

	static FourSeason season_;
};

using Season = SeasonSystem::FourSeason;

