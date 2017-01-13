#ifndef PREFERRED_STOCK_H
#define PREFERRED_STOCK_H

#include "Stock.h"
#include <string>

class PreferredStock : public Stock
{
public:
	PreferredStock(std::string symbol, double lastDividend, double fixedDividend, double parValue);
	~PreferredStock() {};

	double calculateDividendYield(double price) const;
	void showStock(double price) const;

private:
	double fixedDividend;
};

#endif // PREFERRED_STOCK_H