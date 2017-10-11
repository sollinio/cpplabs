#include "Deck.h"
#include "AdapterObject.h"
#include "AdapterClass.h"

#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "Russian");

	Deck deck;
	deck.printDeck();

	//object
	AdapterObject adapterObject;
	adapterObject.prettyPrint(deck);


	//protected method
	AdapterClass a;
	a.format();

	system("pause");
	return 0;
}