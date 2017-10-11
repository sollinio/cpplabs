#pragma once

#include "IFormattable.h"

class AdapterObject
{
public:
	void prettyPrint(IFormattable& object);
	AdapterObject();
	~AdapterObject();
};

