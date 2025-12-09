#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = 0;
        int totalGas = 0;
        int currentGas = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            int fuelGain = gas[i] - cost[i];
            totalGas += fuelGain;
            currentGas += fuelGain;

            if (currentGas < 0)
            {
                currentGas = 0;
                start = i + 1;
            }
        }

        return totalGas < 0 ? -1 : start;
    }
};

int main()
{
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    Solution sl;
    cout << sl.canCompleteCircuit(gas, cost);
}