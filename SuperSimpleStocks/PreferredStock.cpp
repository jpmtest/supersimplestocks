#include "PreferredStock.h"
#include <iostream>

PreferredStock::PreferredStock(std::string symbol,
	double lastDividend,
	double fixedDividend,
	double parValue) : Stock(symbol, lastDividend, parValue)
{
	this->fixedDividend = fixedDividend;
}

double PreferredStock::calculateDividendYield(double price) const
{
	if (price == 0.0)
	{
		throw std::exception("Divide by zero");
	}

	return (fixedDividend * parValue) / price;
}

void PreferredStock::showStock(double price) const
{
	std::cout << symbol <<
		" Last dividend : " << lastDividend <<
		" Fixed dividend : " << fixedDividend <<
		" Par value : " << parValue <<
		" Price : " << price << std::endl;
}