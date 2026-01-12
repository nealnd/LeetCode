#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {

        vector<vector<int>> buy(prices.size(), vector<int>(k));
        vector<vector<int>> sell(prices.size(), vector<int>(k));
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i == 0)
                {
                    buy[i][j] = -prices[i];
                    sell[i][j] = 0;
                }
                else if (j == 0)
                {
                    buy[i][j] = max(buy[i - 1][j], -prices[i]);
                    sell[i][j] = max(sell[i - 1][j], prices[i] + buy[i][j]);
                }
                else
                {
                    buy[i][j] = max(buy[i - 1][j], sell[i][j - 1] - prices[i]);
                    sell[i][j] = max(sell[i - 1][j], prices[i] + buy[i][j]);
                }
            }
        }
        return sell[prices.size() - 1][k - 1];
    }
};

int main()
{
    Solution sl;
    int k = 2;

    vector<int> prices{3, 2, 6, 5, 0, 3};
    cout << sl.maxProfit(k, prices);
}