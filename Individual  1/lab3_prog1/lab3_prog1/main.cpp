#include "ExpressionEvaluator.h"

#include "Multiplier.h"
#include "Subtractor.h"
#include "CustomExpressionEvaluator.h"
#include "ILoggable.h"
#include "IShuffle.h"

#include <iostream>

int main()
{
	ExpressionEvaluator* evaluators[3];
	
	evaluators[0] = new CustomExpressionEvaluator();
	double custom_operands[] = { 5, 16, -3, 10, 12, 2 };
	evaluators[0]->setOperands(custom_operands,6);

	evaluators[1] = new Multiplier();
	double multiplier_operands[] = { 5.6, -2.1, 3.2, 1.5 };
	evaluators[1]->setOperands(multiplier_operands, 4);

	evaluators[2] = new Subtractor();
	evaluators[2]->setOperand(0, 1.5);
	evaluators[2]->setOperand(1, -8);
	evaluators[2]->setOperand(2, 2.5);
	
	for (int i = 0; i < 3; i++)
	{
		evaluators[i]->logToFile("lab3.log");
		evaluators[i]->logToScreen();
		std::cout << "\nResult: " << evaluators[i]->calculate() << std::endl << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		IShuffle* loga = dynamic_cast<IShuffle*>(evaluators[i]);

		if (loga)
		{
			loga->shuffle();
			evaluators[i]->logToScreen();
			std::cout << "\nResult: " << evaluators[i]->calculate() << std::endl << std::endl;
		}
	}
	


	delete evaluators[0];
	delete evaluators[1];
	delete evaluators[2];

	return 0;
}