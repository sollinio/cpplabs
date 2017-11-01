#include "Gambler.h"
#include "Deck.h"

Gambler::Gambler(int money) : money(money) 
{ 
	hands.push_back(new Hand);
}

Gambler::~Gambler() { }

int Gambler::getmoney()
{
	return money;
}

int Gambler::getcounthands()
{
	return hands.size();
}

void Gambler::setmoney(int money)
{
	this->money = money;
}

void Gambler::clear()
{
	hands.clear();
	hands.push_back(new Hand);
}

void Gambler::takeCards(Deck* deck)
{
	int size = hands.size();
	for (int i = 0; i < size; i++)
	{
		hands[i]->takeCard(deck);
	}
}

std::vector<Hand*>& Gambler::getHand()
{
	return hands;
}

void Gambler::split()
{
	int size = hands.size();

	for (int cHand = 0; cHand < size; cHand++)
	{
		if (hands[cHand]->isSplit())
		{
			hands.push_back(new Hand);
			hands[hands.size() - 1]->getCards().push_back(new Card);
			int mid = hands[cHand]->getcountcards() % 2 == 0 ? hands[cHand]->getcountcards() / 2 : hands[cHand]->getcountcards() / 2 + 1;

			for (int i = mid; i < hands[cHand]->getcountcards(); i++)
			{
				std::swap
				(
					hands[cHand]->getCards()[i] , 
					hands[hands.size() - 1]->getCards()[hands[hands.size() - 1]->getcountcards() - 1]
				);
			}
		}
	}
}
