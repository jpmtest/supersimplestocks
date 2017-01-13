#ifndef STOCK_UTILS_H
#define STOCK_UTILS_H

#include "StockUtils.h"
#include "Stock.h"

// used by calculateStockPrice to filter trades from the last 15 minutes
const std::chrono::milliseconds tradeWindow(15 * 60 * 1000);

// utilities for working with stocks
class StockUtils
{
public:
	StockUtils() {};
	~StockUtils() {};

	double calculateStockPrice(const Stock& stock) const;
	double calculateGBCEAllShareIndex(const std::vector<Stock*> stocks) const;
};

#endif // STOCK_UTILS_H