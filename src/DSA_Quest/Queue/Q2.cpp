#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {

        int i = 0;
        int count = 0;
        while (tickets[k] > 0)
        {
            if (tickets[i] >= 1)
            {
                tickets[i]--;
                count++;
            }
            if (i == tickets.size() - 1)
                i = 0;
            else
                i++;
        }
        return count;
    }
};

int main()
{
    vector<int> tickets{2, 3, 2};
    int k = 2;
    Solution sl;
    cout << sl.timeRequiredToBuy(tickets, k);
}