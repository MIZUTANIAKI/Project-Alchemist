#pragma once

class ConstellationSystem
{
public:
	void Update(void);
	void Init(void);
	
	/// <summary>
	/// êØç¿ÉäÉXÉg
	/// </summary>
	enum Constellation
	{
		Mizugameza,
		Uoza,
		Ohituziza,
		Ousiza,
		Futagoza,
		Kaniza,
		Sisiza,
		Otomeza,
		Tenbinza,
		Sasoriza,
		Iteza,
		Yagiza,
		Max
	};

	static Constellation GetConstellation(void);
private:
	void SetNextConstellation(void);

	static Constellation constellation_;
};

using Astrogical = ConstellationSystem::Constellation;

