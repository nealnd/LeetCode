#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> buy(prices.size(), vector<int>(2, INT_MAX));
        vector<vector<int>> sell(prices.size(), vector<int>(2, INT_MIN));

        for (int i = 0; i < prices.size(); i++)
        {
            if (i == 0)
            {
                buy[i][0] = -prices[i];
                sell[i][0] = 0;
                buy[i][1] = -prices[i];
                sell[i][1] = 0;
            }
            else
            {
                buy[i][0] = max(-prices[i], buy[i - 1][0]);
                sell[i][0] = max(sell[i - 1][0], prices[i] + buy[i][0]);
                buy[i][1] = max(sell[i - 1][0] - prices[i], buy[i - 1][1]);
                sell[i][1] = max(sell[i - 1][1], prices[i] + buy[i - 1][1]);
            }
        }
        return sell[prices.size() - 1][1];
    }
};

