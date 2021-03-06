#include "Deck.h"
#include "Enum.h"
#include "Card.h"

#include <random>
#include <ctime>
#include <iostream>

Deck::Deck()
{
	initDeck(TypeDeck::Cut);
}


int Deck::getCountCards()
{
	return countCards;
}

int Deck::getNumberCard()
{
	return numbercard;
}

Card Deck::takeCard()
{
	++numbercard;
	return cards[numbercard - 1];
}

void Deck::createDeck()
{
	int start = (countCards == 52) ? 2 : 6;
	int markCard = 0;
	for (int csuit = 0; csuit < countSuit; csuit++)
	{
		for (int cname = start; cname < countCards / countSuit + start; cname++)
		{
				cards[markCard].setName((NameCard)cname);
				cards[markCard++].setSuit((Suit)csuit);
		}
	}
}

void Deck::shuffleDeck()
{
	//srand(time(0));
	for (int i = 1; i < countCards; i++)
	{
		std::swap(cards[i], cards[(rand() % i)]);
	}
}

void Deck::initDeck(TypeDeck type)
{
	if (type == TypeDeck::Cut)
		countCards = 36;
	if (type == TypeDeck::Full)
		countCards = 52;
	cards = new Card[countCards];
	createDeck();
	//shuffleDeck();
}

void Deck::printDeck()
{
	for (int i = 0; i < countCards; i++)
	{
		std::cout << cards[i].getsCard() + " ";
	}
}

Deck::~Deck()
{
	delete[] cards;
}

std::string Deck::format()
{
	std::string outstring = "its obj pretty print: ";
	std::cout << "\n\nits pretty print: ";

	for (int i = 0; i < countCards; i++)
	{
		std::cout << "|" << cards[i].getsCard() << "| ";
	}
	return outstring;
}