#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        for (int i = 0; i < n; i++)
        {
            if (citations[i] >= n - i)
            {
                return n - i;
            }
        }

        return 0;
    }
};

int main()
{
    vector<int> citations{3, 0, 6, 1, 5};
    Solution sl;
    cout << sl.hIndex(citations);
}