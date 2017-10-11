#pragma once

#include "Enum.h"
#include "Card.h"
#include "IFormattable.h"

class Deck : public IFormattable
{
private:
	void createDeck();
	void shuffleDeck();

	std::string format();
protected:
	int numbercard = 0;
	Card* cards;
	int countCards;
	const int countSuit = 4;
public:
	Deck();
	void initDeck(TypeDeck type);
	int getCountCards();
	int getNumberCard();
	Card takeCard();

	void printDeck();
	~Deck();
};

