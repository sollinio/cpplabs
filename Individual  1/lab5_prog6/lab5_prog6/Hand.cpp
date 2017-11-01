#include "Hand.h"
#include "Deck.h"

#include <ctime>
#include <random>

Hand::Hand() { }
Hand::~Hand() { }

int Hand::getmaxcardscount()
{
	return maxcardscount;
}

int Hand::checkValueAce(int value, int countAce)
{
	int aceValue = 0;
	for (int i = 0; i < countAce; i++)
	{
		if (value + 11 <= 21)
		{
			value += 11;
			aceValue += 11;
		}
		else
		{
			value += 11;
			aceValue += 1;
		}

	}
	return aceValue;
}

bool Hand::checkBJ(int value)
{
	if (value == 21 && cardscount == 2)
	{
		return true;
	}
	return false;
}

bool Hand::checkGBJ(int value)
{
	if (value == 12 && cardscount == 2)
	{
		if(cards[0]->getName() == NameCard::Ace && cards[1]->getName()  == NameCard::Ace)
			return true;
	}
	return false;
}

int Hand::calculateValue()
{
	int countAce = 0;
	int value = 0;
	for (int i = 0; i < cardscount; i++)
	{
		switch (cards[i]->getName())
		{
		case NameCard::Jack:
			value += 10;
			break;
		case NameCard::Queen:
			value += 10;
			break;
		case NameCard::King:
			value += 10;
			break;
		case NameCard::Ace:
			countAce++;
			break;
		default:
			value += (int)cards[i]->getName();
			break;
		}
	}
	value += checkValueAce(value, countAce);

	if (checkGBJ(value))
		return 101;
	if (checkBJ(value))
		return 100;

	return value;
}

void Hand::clear()
{
	cards.clear();
}

void Hand::takeCard(Deck* deck)
{
	cards.push_back(deck[random()].takeCard());
}

int Hand::random()
{
	srand(time(0));
	return rand() % 4;
}

int Hand::getcountcards()
{
	return cards.size();
}

void Hand::setcountcards(int cardscount)
{
	this->cardscount = cardscount;
}

std::vector<Card*>& Hand::getCards()
{
	return cards;
}

bool Hand::isSplit()
{
	for (int i = 0; i < getcountcards(); i++)
	{
		for (int j = 0; j < getcountcards(); j++)
		{
			if (i != j  && cards[i]->getName() == cards[j]->getName() && (int)cards[j]->getName() <= 10)
			{
				return true;
			}

			if (i != j && (int)cards[i]->getName() > 10 && (int)cards[j]->getName() > 10)
			{
				return true;
			}
		}
	}
	return false;
}