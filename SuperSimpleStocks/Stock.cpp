#include "Stock.h"
#include <iostream>

Stock::Stock(std::string symbol, double lastDividend, double parValue)
{
	this->symbol = symbol;
	this->lastDividend = lastDividend;
	this->parValue = parValue;
}

double Stock::calculatePERatio(double price) const
{
	// the formula given states PE ratio is calculated from price divided by dividend.
	// it's unclear whether this refers to last dividend, fixed dividend, dividend yield or something else.
	// i'm using last dividend here - this needs to be verified.
	if (lastDividend == 0.0)
	{
		// the test data given has a last dividend value of 0 for stock TEA. assuming this is a valid value, 
		// we return 0 here to avoid a divide by zero. if 0 is not a valid value for last dividend, an 
		// exception should be thrown instead.
		return 0.0;
	}

	return price / lastDividend;
}

void Stock::buy(unsigned long quantity, double price)
{
	trades.push_back(Trade(quantity, TradeType::BUY, price));
}

void Stock::sell(unsigned long quantity, double price)
{
	trades.push_back(Trade(quantity, TradeType::SELL, price));
}
