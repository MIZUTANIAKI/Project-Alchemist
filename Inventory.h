#pragma once
#include <array>

class Inventory
{
public:
	Inventory();
	~Inventory();
	
private:
	std::array<int, 32> itemInventory_;
};

