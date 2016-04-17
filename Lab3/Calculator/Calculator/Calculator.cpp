#include "stdafx.h"
#include "Calculator.h"

CCalculator::CCalculator()
{
}

double CCalculator::Add(double var1, double var2)
{
	return var1 + var2;
}

double CCalculator::Multiply(double var1, double var2)
{
	return var1 * var2;
}

double CCalculator::Substract(double var1, double var2)
{
	return var1 - var2;
}

double CCalculator::Divide(double var1, double var2)
{
	return var1 / var2;
}


CCalculator::~CCalculator()
{
}
