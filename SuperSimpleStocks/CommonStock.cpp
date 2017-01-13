#include "CommonStock.h"
#include <iostream>

double CommonStock::calculateDividendYield(double price) const
{
	if (price == 0.0)
	{
		throw std::exception("Divide by zero");
	}

	return lastDividend / price;
}

void CommonStock::showStock(double price) const
{
	std::cout << symbol <<
		" Last dividend : " << lastDividend <<
		" Par value : " << parValue <<
		" Price : " << price << std::endl;
}