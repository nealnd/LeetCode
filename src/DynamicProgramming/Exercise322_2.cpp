/* Note: where to cache the result is important*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -2);
        dp[0] = 0;
        for (auto coin : coins)
        {
            if (coin <= amount)
                dp[coin] = 1;
        }

        return coinChangeHelper(dp, amount, coins);
    }

private:
    int coinChangeHelper(vector<int> &dp, int amount, vector<int> &coins)
    {

        if (dp[amount] != -2)
            return dp[amount];

        int min_count = INT_MAX;

        for (auto coin : coins)
        {
            if (amount - coin >= 0)
            {
                int res = coinChangeHelper(dp, amount - coin, coins);
                if (res >= 0 && res < min_count)
                    min_count = 1 + res;
            }
        }

        // Cache the result before returning
        dp[amount] = (min_count == INT_MAX) ? -1 : min_count;

        return dp[amount];
    }
};

int main()
{
    vector<int> coins{186, 419, 83, 408};
    int amount = 6249;
    Solution sl;
    cout << sl.coinChange(coins, amount);
}

/* a time limit exceeded answer

class Solution {
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (auto coin : coins)
        {
            if (coin <= amount)
                dp[coin] = 1;
        }

        return coinChangeHelper(dp, amount, coins) == INT_MAX ? -1 : coinChangeHelper(dp, amount, coins);
    }

private:
    int coinChangeHelper(vector<int> &dp, int amount, vector<int> &coins)
    {

        if (dp[amount] != INT_MAX)
            return dp[amount];

        for (auto coin : coins)
        {
            if (amount - coin >= 0)
            {
                dp[amount - coin] = coinChangeHelper(dp, amount - coin, coins);
                if (dp[amount - coin] != INT_MAX)
                    dp[amount] = min(dp[amount], dp[amount - coin] + 1);
            }
        }

        return dp[amount];
    }
};

*/