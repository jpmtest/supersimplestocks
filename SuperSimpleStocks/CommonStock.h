#ifndef COMMON_STOCK_H
#define COMMON_STOCK_H

#include "Stock.h"
#include <string>

class CommonStock : public Stock
{
public:
	CommonStock(std::string symbol, double lastDividend, double parValue) : Stock(symbol, lastDividend, parValue) {}
	~CommonStock() {};

	double calculateDividendYield(double price) const;
	void showStock(double price) const;
};

#endif // COMMON_STOCK_H