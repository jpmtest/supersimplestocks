#include "StockUtils.h"
#include "PreferredStock.h"
#include <iostream>

double StockUtils::calculateStockPrice(const Stock& stock) const
{
	double totalPrice = 0.0;
	unsigned long totalQuantity = 0;

	std::chrono::time_point<std::chrono::system_clock> currentTime = std::chrono::system_clock::now();

	const std::vector<Trade> &trades = stock.getTrades();

	if (trades.size() == 0)
	{
		return 0.0;
	}

	for (Trade trade : trades)
	{
		// ignore trades older than 15 minutes
		if (currentTime - trade.getTimeStamp() > tradeWindow) { continue; }

		totalPrice += trade.getPrice() * trade.getQuantity();
		totalQuantity += trade.getQuantity();
	}

	if (totalQuantity == 0)
	{
		throw std::exception("Divide by zero");
	}

	return totalPrice / totalQuantity;
}

double StockUtils::calculateGBCEAllShareIndex(const std::vector<Stock*> stocks) const
{
	double total = 1.0;
	double result;
	unsigned long int numStocks = 0;

	for (Stock* stock : stocks)
	{
		result = calculateStockPrice(*stock);

		if (result != 0.0)
		{
			total *= result;
			numStocks++;
		}
	}

	if (numStocks == 0)
	{
		throw std::exception("Divide by zero");
	}

	return std::pow(total, 1.0 / numStocks);
}