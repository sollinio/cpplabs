#include "Deck.h"
#include "Enum.h"
#include "Card.h"

#include <random>
#include <ctime>
#include <iostream>

Deck::Deck() { }
Deck::~Deck() { }

int Deck::getCountCards()
{
	return countCards;
}

int Deck::getNumberCard()
{
	return countCards - cards.size();
}

Card* Deck::takeCard()
{
	Card* tmp = cards.at(cards.size() - 1);
	cards.pop_back();
	return tmp;
}

void Deck::createDeck()
{
	int start = (countCards == 52) ? 2 : 6;
	for (int csuit = 0; csuit < countSuit; csuit++)
		for (int cname = start; cname < countCards / countSuit + start; cname++)
			cards.push_back(new Card((Suit)csuit, (NameCard)cname));
}

void Deck::shuffleDeck()
{
	std::random_shuffle(cards.begin(),cards.end());
}

void Deck::initDeck(TypeDeck type)
{
	if (type == TypeDeck::Cut)
		countCards = 36;
	if (type == TypeDeck::Full)
		countCards = 52;
	createDeck();
	shuffleDeck();
}
