#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int Max = -INT_MAX, result = -1;
        int SuffixSum = 0;
        for (int i = gas.size() - 1; i >= 0; i--)
        {
            int Remnant = gas[i] - cost[i];
            SuffixSum += Remnant;
            if (SuffixSum > Max)
            {
                Max = SuffixSum;
                result = i;
            }
        }
        if (SuffixSum < 0)
            return -1;
        return result;
    }
};

int main()
{
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    Solution sl;
    cout << sl.canCompleteCircuit(gas, cost);
}