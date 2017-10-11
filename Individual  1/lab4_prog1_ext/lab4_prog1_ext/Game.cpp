
#include <iostream>
#include <ctime>

#include "Game.h"
#include "Gambler.h"
#include "Dealer.h"


Game::Game(Dealer* dealers, Gambler* gambler) : dealers(dealers), gambler(gambler) { }
Game::~Game() { }

void Game::setDecks(Deck* deck)
{
	this->deck = deck;
}

bool Game::init()
{
	if (0 >= gambler->getmoney())
	{
		std::cout << "\nВаш баланс пуст, совершите депозит либо устройтесь на работу :)";
		std::cout << "\nУдачи\n";
	
	}

	int tmp_money;
	std::cout << "\nВаш счет: " << gambler->getmoney();
	std::cout << "\nВаша ставка: ";
	std::cin >> tmp_money;

	if (tmp_money <= 0)
	{
		std::cout << "\nВаша ставка не может быть меньше или равна 0";
		return false;
	}

	if (tmp_money <= gambler->getmoney())
	{
		gambler->setmoney(gambler->getmoney() - tmp_money);
		cash = tmp_money;
		return true;
	}
	else
	{
		std::cout << "\nНехватает денег для ставки";
		return false;
	}	
}

void Game::printCardsGambler()
{
	std::cout << "\nВаши карты : ";
	for (int i = 0; i < 12 ; i++)
	{
		if (gambler->getCards()[i].getName() != NameCard::None)
			std::cout << gambler->getCards()[i];
	}
	std::cout << std::endl;
}

void Game::getAllCards()
{
	for (int i = 0; i < 36/4 ; i++)
	{
		gambler->takeCard(deck);
		for (int j = 0; j < 3; j++)
		{
			dealers[j].takeCard(deck);
		}
	}
	deleteCloneCards();
}

void Game::printCardsDealer(bool isVisible)
{
	for (int d = 0; d < 3; d++)
	{
		std::cout << "\nИгрок " << d + 1 << " : ";

		if (isVisible == 0)
		{
			for (int i = 0; i < 12; i++)
			{
				if (dealers[d].getCards()[i].getName() != NameCard::None)
					std::cout << "?? ";
			}
		}
		else
		{
			for (int i = 0; i < 12; i++)
			{
				if(dealers[d].getCards()[i].getName() != NameCard::None)
					std::cout << dealers[d].getCards()[i];
			}
		}
	}
}

void Game::deleteCloneCards()
{
	gambler->deleteCloneCards();
	for (int j = 0; j < 3; j++)
	{
		dealers[j].deleteCloneCards();
	}
}



void Game::printMenu()
{
	if (gambler->getcountcards() != 0 && dealers[infinity % 3].getcountcards() != 0)
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "0 - если хотите сдаться" << std::endl;
		std::cout << "Вы берете карту у игрока под номером: " << (infinity % 3) + 1 << std::endl;
		std::cout << "Введите номер карты: " << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
}


int Game::getChoice()
{
	//last card Spade Quuen | -2 code end the game and print result
	if (gambler->getcountcards() + dealers[0].getcountcards() + dealers[1].getcountcards() + dealers[2].getcountcards() == 1)
		return -2;
	//gambler or dealer not exist cards | -1 code swap cards bots
	if (gambler->getcountcards() == 0 || dealers[infinity % 3].getcountcards() == 0)
		return -1;
	int tmp;
	std::cin >> tmp;
	return tmp;
}

bool Game::replicateChoice(int choice)
{
	switch (choice)
	{
	case -2:
		printCardsDealer(1);
		printCardsGambler();
		calculateScore();
		return false;
	case -1:
		swapCardsBot(); 
		break;
	case 0:
		return false;
	default:
		swapCards(choice);
		break;
	}
	infinity++;
	return true;
}

void Game::calculateScore()
{
	if (gambler->getcountcards() == 0)
	{
		std::cout << "Вы выиграли" << std::endl;
		gambler->setmoney(gambler->getmoney() + (cash * 2));
	}
	else
		std::cout << "Вы проиграли" << std::endl;
}

void Game::dropCards()
{
	dealers[0].clear();
	dealers[1].clear();
	dealers[2].clear();
	gambler->clear();
	infinity = 0;
}

//take one -> to second 
void Game::getCardsAnotherPlayer(Player* one, Player* two, int number)
{
	if (one->getcountcards() == 0 || two->getcountcards() == 0)
		return;

	std::cout << "\n\nВыбрана карта: " << one->getCards()[number] << std::endl;

	std::swap(one->getCards()[number], two->getCards()[11]);

	one->deleteCloneCards();
	two->deleteCloneCards();

	std::cout << "\n\nТекущая ситуация: " << std::endl;
	printCardsDealer(0);
	printCardsGambler();
}

void Game::swapCards(int gamblernumber)
{
	static int seed = 0;
	srand(time(0) + 0);

	if (dealers[infinity % 3].getcountcards() == 0)
		return;
	getCardsAnotherPlayer(&dealers[infinity % 3], gambler, gamblernumber - 1);

	

	if (gambler->getcountcards() == 0)
		return;
	int tmp_number = rand() % gambler->getcountcards();

	getCardsAnotherPlayer(gambler, &dealers[infinity % 3], tmp_number);

	swapCardsBot();
}

void Game::swapCardsBot()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != j && i != infinity && j != infinity)
			{
				if (dealers[i].getcountcards() == 0 || dealers[j].getcountcards() == 0)
					continue;
				int tmp_number = rand() % dealers[i].getcountcards();
				getCardsAnotherPlayer(&dealers[i], &dealers[j], tmp_number);
			}
		}
	}

}
