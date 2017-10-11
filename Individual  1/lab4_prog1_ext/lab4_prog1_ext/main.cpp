#include <locale>
#include <cstdlib>

#include "Deck.h"
#include "Enum.h"
#include "Gambler.h"
#include "Dealer.h"
#include "Game.h"


int main()
{
	setlocale(LC_ALL,"Russian");

	Deck* deck = new Deck();
	deck->initDeck(TypeDeck::Cut);

	Gambler* gambler = new Gambler(9999);
	Dealer* dealer = new Dealer[3]();

	Game game(dealer, gambler);
	game.setDecks(deck);

		game.getAllCards();
		do
		{
			game.deleteCloneCards();
			game.printMenu();
		} while (game.replicateChoice(game.getChoice()));

		game.dropCards();

	delete deck;
	delete gambler;

	system("pause");
	return 0;
}