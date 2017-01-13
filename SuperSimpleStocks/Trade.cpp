#include "Trade.h"
#include <iostream>
#include <ctime>

Trade::Trade(unsigned long quantity, TradeType tradeType, double price)
{
	this->timeStamp = std::chrono::system_clock::now();
	this->quantity = quantity;
	this->tradeType = tradeType;
	this->price = price;
}
