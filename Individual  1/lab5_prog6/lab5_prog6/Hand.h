#pragma once

#include <vector>
#include <algorithm>

#include "Card.h"
#include "Deck.h"

class Hand
{
private:
	std::vector <Card*> cards;
	int cardscount = 0;

	const int maxcardscount = 11;

	int random();
	int checkValueAce(int value, int countAce);
	
public:
	std::vector<Card*>& getCards();
	int getmaxcardscount();
	int getcountcards();
	
	void setcountcards(int cardscount);
	int calculateValue();
	void clear();
	void takeCard(Deck* deck);

	bool isSplit();

	bool checkBJ(int value);
	bool checkGBJ(int value);

	Hand();
	virtual ~Hand();
};

