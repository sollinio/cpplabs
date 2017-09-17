#pragma once
class ISalaryCalculation
{
public:
	virtual double calculate() = 0;
	virtual ~ISalaryCalculation() { };
};

