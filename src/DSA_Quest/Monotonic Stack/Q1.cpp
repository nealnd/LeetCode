#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        stack<pair<int, int>> temp;
        vector<int> result(prices.begin(), prices.end());
        for (int i = 0; i < prices.size(); i++)
        {
            if (temp.empty() || prices[i] > temp.top().second)
            {
                temp.push(pair<int, int>(i, prices[i]));
            }
            else
            {
                while (!temp.empty() && prices[i] <= temp.top().second)
                {
                    result[temp.top().first] = temp.top().second - prices[i];
                    temp.pop();
                }
                temp.push(pair<int, int>(i, prices[i]));
            }
        }
        return result;
    }
};

int main(){
    vector<int> prices{8, 4, 6, 2, 3};
    Solution sl;
    for (auto dis : sl.finalPrices(prices))
        cout << dis << " ";
}