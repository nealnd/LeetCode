#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int currentProfit = 0;
        int maxPro = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            currentProfit = max(0, currentProfit += prices[i] - prices[i - 1]);
            maxPro = max(maxPro, currentProfit);
        }
        return maxPro;
    }
};

int main()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    Solution sl;
    cout << sl.maxProfit(prices);
}