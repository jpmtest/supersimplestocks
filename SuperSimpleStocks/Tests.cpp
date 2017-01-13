#include "Tests.h"
#include "CommonStock.h"
#include "PreferredStock.h"
#include <iostream>

void Tests::RunTests(const StockUtils& stockUtils)
{
	std::cout << "Running tests..." << std::endl;

	// create some test stocks
	CommonStock* stockTEA = new CommonStock("TEA", 0.0, 100.0);
	CommonStock* stockPOP = new CommonStock("POP", 8.0, 100.0);
	CommonStock* stockALE = new CommonStock("ALE", 23.0, 60.0);
	PreferredStock* stockGIN = new PreferredStock("GIN", 8.0, 2.0, 100.0);
	CommonStock* stockJOE = new CommonStock("JOE", 13.0, 250.0);

	// generate some trades
	stockTEA->buy(100, 500.0);
	stockTEA->buy(200, 450.0);
	stockTEA->sell(50, 525.0);

	stockPOP->buy(300, 600.0);
	stockPOP->sell(600, 550.0);
	stockPOP->sell(20, 850.0);

	stockALE->buy(1000, 678.0);
	stockALE->sell(1000, 678.0);
	stockALE->buy(897, 544.0);
	stockALE->sell(50, 2050.0);

	stockGIN->buy(20, 90000.0);
	stockGIN->sell(100, 0.754);
	stockGIN->buy(10000, 2500.0);
	stockGIN->sell(14000, 2600.0);
	stockGIN->sell(300, 18750.0);

	stockJOE->buy(333, 650.0);
	stockJOE->buy(758, 632.0);
	stockJOE->sell(1435, 681.0);

	// show stock info with price
	stockTEA->showStock(stockUtils.calculateStockPrice(*stockTEA));
	stockPOP->showStock(stockUtils.calculateStockPrice(*stockPOP));
	stockALE->showStock(stockUtils.calculateStockPrice(*stockALE));
	stockGIN->showStock(stockUtils.calculateStockPrice(*stockGIN));
	stockJOE->showStock(stockUtils.calculateStockPrice(*stockJOE));

	stocks.push_back(stockTEA);
	stocks.push_back(stockPOP);
	stocks.push_back(stockALE);
	stocks.push_back(stockGIN);
	stocks.push_back(stockJOE);

	bool result = false;
	unsigned int testsPassed = 0;
	unsigned int numTests = 16;

	// run tests
	try
	{
		testsPassed += testPrice(*stockTEA, stockUtils, 475.0);
		testsPassed += testPrice(*stockPOP, stockUtils, 572.826);
		testsPassed += testPrice(*stockALE, stockUtils, 660.4913);
		testsPassed += testPrice(*stockGIN, stockUtils, 2818.3897);
		testsPassed += testPrice(*stockJOE, stockUtils, 662.2094);

		testsPassed += testDividendYield(*stockTEA, stockUtils.calculateStockPrice(*stockTEA), 0.0);
		testsPassed += testDividendYield(*stockPOP, stockUtils.calculateStockPrice(*stockPOP), 0.01396);
		testsPassed += testDividendYield(*stockALE, stockUtils.calculateStockPrice(*stockALE), 0.0348);
		testsPassed += testDividendYield(*stockGIN, stockUtils.calculateStockPrice(*stockGIN), 0.0709);
		testsPassed += testDividendYield(*stockJOE, stockUtils.calculateStockPrice(*stockJOE), 0.0196);

		testsPassed += testPERatio(*stockTEA, stockUtils.calculateStockPrice(*stockTEA), 0.0);
		testsPassed += testPERatio(*stockPOP, stockUtils.calculateStockPrice(*stockPOP), 71.6032);
		testsPassed += testPERatio(*stockALE, stockUtils.calculateStockPrice(*stockALE), 28.717);
		testsPassed += testPERatio(*stockGIN, stockUtils.calculateStockPrice(*stockGIN), 352.2987);
		testsPassed += testPERatio(*stockJOE, stockUtils.calculateStockPrice(*stockJOE), 50.9391);

		testsPassed += testAllShareIndex(stocks, stockUtils, 803.7407);
	}
	catch (std::exception e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << numTests << " tests complete. " << testsPassed << " tests passed." << std::endl;
}

bool Tests::testPrice(const Stock& stock, const StockUtils& stockUtils, double expected) const
{
	double result = stockUtils.calculateStockPrice(stock);

	if (std::fabs(result - expected) < errorMargin)
	{
		return true;
	}

	return false;
}

bool Tests::testDividendYield(const Stock& stock, double price, double expected) const
{
	double result = stock.calculateDividendYield(price);

	if (std::fabs(result - expected) < errorMargin)
	{
		return true;
	}

	return false;
}

bool Tests::testPERatio(const Stock& stock, double price, double expected) const
{
	double result = stock.calculatePERatio(price);

	if (std::fabs(result - expected) < errorMargin)
	{
		return true;
	}

	return false;
}

bool Tests::testAllShareIndex(const std::vector<Stock*> stocks, const StockUtils& stockUtils, double expected) const
{
	double result = stockUtils.calculateGBCEAllShareIndex(stocks);

	if (std::fabs(result - expected) < errorMargin)
	{
		return true;
	}

	return false;
}
