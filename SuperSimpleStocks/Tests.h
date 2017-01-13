#ifndef TESTS
#define TESTS

#include "Stock.h"
#include "StockUtils.h"

// used when comparing the expected and actual values in the various tests to allow a small margin of error
const double errorMargin(0.01);

class Tests
{
public:
	Tests() {};
	~Tests() {};

	void RunTests(const StockUtils& stockUtils);

	bool testPrice(const Stock& stock, const StockUtils& stockUtils, double expected) const;
	bool testDividendYield(const Stock& stock, double price, double expected) const;
	bool testPERatio(const Stock& stock, double price, double expected) const;
	bool testAllShareIndex(const std::vector<Stock*> stocks, const StockUtils& stockUtils, double expected) const;

private:
	std::vector<Stock*> stocks;
};

#endif // TESTS