#pragma once
#include "Constellation.h"

class DateSystem
{
public:
	void Update(void);
	void Init(void);
	void Init(int month, int day);
	
	static bool NowChangeMonth(void);
	static int GetMonth(void);
	static int GetDay(void);
private:
	void MonthUp();
	static int month_;
	static int day_;
	static bool changeF_;
};

