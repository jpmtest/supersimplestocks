#ifndef TRADE_H
#define TRADE_H

#include <chrono>

typedef std::chrono::time_point<std::chrono::system_clock> TimeStamp;

enum TradeType
{
	BUY,
	SELL
};

class Trade
{
public:
	Trade(unsigned long quantity, TradeType tradeType, double price);
	~Trade() {};

	TimeStamp getTimeStamp() const { return timeStamp; }
	unsigned long getQuantity() const { return quantity; }
	double getPrice() const { return price; }

private:
	TimeStamp timeStamp;
	unsigned long quantity;
	TradeType tradeType;
	double price;
};

#endif // TRADE_H