#include "Player.h"


#include <ctime>
#include <random>

Player::Player()
{
	 cards = new Card[maxcards];
}


Player::~Player()
{
}

void Player::clear()
{
	for (int i = 0; i < maxcards; i++)
	{
		cards[i].setName(NameCard::None);
		cards[i].setSuit(Suit::None);
		cardscount = 0;
	}
}

Card* Player::getCards()
{
	return cards;
}

void Player::takeCard(Deck* deck)
{
	cards[cardscount++] = deck->takeCard();
}

int Player::random()
{
	srand(time(0));
	return rand() % 4;
}

int Player::getcountcards()
{
	return cardscount;
}

void Player::setcountcards(int cardscount)
{
	this->cardscount = cardscount;
}

void Player::deleteCloneCards()
{
	//delete clone
	for (int i = 0; i < maxcards; i++)
	{

		for (int j = 0; j < maxcards; j++)
		{
			if (
				getCards()[i].getName() == NameCard::Queen && getCards()[i].getSuit() == Suit::Spade
				|| getCards()[j].getName() == NameCard::Queen && getCards()[j].getSuit() == Suit::Spade
				) 
			{
				continue;
			}
			
			else if (
				getCards()[j].getName() == getCards()[i].getName()
				&& i != j
				&& getCards()[j].getName() != NameCard::None				
				)
			{

				getCards()[i].setName(NameCard::None);
				getCards()[j].setName(NameCard::None);
				getCards()[i].setSuit(Suit::None);
				getCards()[j].setSuit(Suit::None);
			}			
		}
	}

	//sort
	int mid = getcountcards();
	for (int i = 0; i < maxcards; i++)
	{
		if (getCards()[i].getName() == NameCard::None)
		{
			for (int j = i; j < maxcards; j++)
			{
				if (getCards()[j].getName() != NameCard::None)
				{
					std::swap(getCards()[i], getCards()[j]);
				}
			}
		}

	}

	//recount
	for (int i = 0; i < mid; i++)
	{
		if (getCards()[i].getName() == NameCard::None)
		{
			setcountcards(i);
			break;
		}
	}

}