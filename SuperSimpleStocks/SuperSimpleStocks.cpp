#include <iostream>
#include "Stock.h"
#include "CommonStock.h"
#include "PreferredStock.h"
#include "StockUtils.h"
#include "Tests.h"

int main()
{
	StockUtils* stockUtils = new StockUtils();
	Tests* tests = new Tests();
	tests->RunTests(*stockUtils);

	system("pause");

    return 0;
}
