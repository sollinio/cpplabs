#include "Gambler.h"
#include "Deck.h"


Gambler::Gambler(int money) : money(money)
{
}

Gambler::~Gambler()
{ 
	
}

int Gambler::getmoney()
{
	return money;
}


void Gambler::setmoney(int money)
{
	this->money = money;
}