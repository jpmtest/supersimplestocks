#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>
#include "Trade.h"

// abstract Stock base class. CommonStock and PreferredStock are derived from it
class Stock
{
public:
	Stock(std::string symbol, double lastDividend, double parValue);
	~Stock() {};

	std::string getSymbol() const { return symbol; }
	double getLastDividend() const { return lastDividend; }
	double getParValue() const { return parValue; }
	double calculatePERatio(double price) const;
	virtual double calculateDividendYield(double price) const = 0;

	// records the buying or selling of this stock
	void buy(unsigned long quantity, double price);
	void sell(unsigned long quantity, double price);

	const std::vector<Trade>& getTrades() const { return trades; }

	virtual void showStock(double price) const = 0;

protected:
	std::string symbol;
	double lastDividend;
	double parValue;

private:
	// stores a record of all trades of this stock
	std::vector<Trade> trades;
};

#endif // STOCK_H