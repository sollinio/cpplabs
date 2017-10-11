#pragma once

#include "Deck.h"

class Player
{
	int cardscount = 0;
	const int maxcards = 12;
	Card* cards;
public:
	void clear();

	Card* getCards();
	int getcountcards();
	void setcountcards(int cardscount);
	void takeCard(Deck* deck);
	int random();

	void deleteCloneCards();

	Player();
	virtual ~Player();
};

