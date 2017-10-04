#pragma once

#include "ExpressionEvaluator.h"

class Multiplier : public ExpressionEvaluator
{
public:
	Multiplier();
	~Multiplier();

	double calculate();
	void logToScreen();
	void logToFile(const std::string& filename);
};

