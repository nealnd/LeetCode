#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int maxProfitWithKTransactions(vector<int> &prices, int k)
    {
        int n = prices.size();

        // dpNext[op] : max profit from day (i+1) at operation 'op'
        // dpCurr[op] : max profit from day i at operation 'op'
        vector<int> dpCurr(2 * k + 1, 0);
        vector<int> dpNext(2 * k + 1, 0);

        // Iterate days from back to front
        for (int day = n - 1; day >= 0; day--)
        {
            for (int op = 0; op < 2 * k; op++)
            {

                // Even operation index → Buy
                if (op % 2 == 0)
                {
                    int buy = -prices[day] + dpNext[op + 1];
                    int skip = dpNext[op];
                    dpCurr[op] = max(buy, skip);
                }
                // Odd operation index → Sell
                else
                {
                    int sell = prices[day] + dpNext[op + 1];
                    int skip = dpNext[op];
                    dpCurr[op] = max(sell, skip);
                }
            }
            dpNext = dpCurr; // move to previous day
        }

        // Start from day 0, operation 0 (first buy)
        return dpNext[0];
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        return maxProfitWithKTransactions(prices, k);
    }
};
