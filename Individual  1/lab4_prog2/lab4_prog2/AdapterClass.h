#pragma once

#include "IFormattable.h"
#include "Deck.h"

class AdapterClass : private IFormattable, public Deck
{
public:
	std::string format();
	void adjust();
	AdapterClass();
	~AdapterClass();
};

