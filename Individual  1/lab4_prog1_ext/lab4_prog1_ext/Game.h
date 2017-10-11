#pragma once

#include "Gambler.h"
#include "Dealer.h"
#include "Deck.h"
#include "Card.h"

class Game
{
	int cash; 
	Deck* deck;

	int infinity;

	Dealer* dealers;
	Gambler* gambler;


public:
	Game(Dealer* dealer, Gambler* gambler);
	~Game();

	void setDecks(Deck* decks);
	void getAllCards();
	void Game::deleteCloneCards();

	int getChoice();

	void calculateScore();
	
	void printCardsDealer(bool variant);
	void printCardsGambler();
	void printMenu();	
	void dropCards();
	bool init();
	bool replicateChoice(int choice);
	void getCardsAnotherPlayer(Player* one, Player* two, int number);
	void swapCards(int gamblernumber);
	void swapCardsBot();
};

