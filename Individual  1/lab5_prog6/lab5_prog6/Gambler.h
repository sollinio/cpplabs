#pragma once

#include <vector>

#include "Hand.h"
#include "Deck.h"

class Gambler
{
private:
	int money;

	std::vector<Hand*> hands;

	
public:
	std::vector<Hand*>& getHand();
	int getmoney();
	int getcounthands();
	void setcounthands(int counthands);
	void setmoney(int money);
	
	void split();

	void clear();
	void takeCards(Deck* deck);

	Gambler(int money);
	~Gambler();
};

