#pragma once

#include <string>

class IFormattable
{
public:
    virtual std::string format() = 0;
	IFormattable(){ };
	virtual ~IFormattable(){ }

};

