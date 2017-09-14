#pragma once

#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class Subtractor : public ExpressionEvaluator, public IShuffle
{
public:
	Subtractor();
	~Subtractor();

	double calculate();
	void logToScreen();
	void logToFile(const std::string& filename);

	void shuffle();
	void shuffle(size_t i, size_t j);
};

