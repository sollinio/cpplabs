#pragma once

#include "Player.h"


class Gambler : public Player
{
private:
	int money;

public:
	int getmoney();
	void setmoney(int money);
	
	Gambler(int money);
	~Gambler();
};

