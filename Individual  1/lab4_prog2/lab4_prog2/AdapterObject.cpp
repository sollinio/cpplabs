#include "AdapterObject.h"
#include "Deck.h"


AdapterObject::AdapterObject()
{
}


AdapterObject::~AdapterObject()
{
}

void AdapterObject::prettyPrint(IFormattable& object)
{
	object.format();
}