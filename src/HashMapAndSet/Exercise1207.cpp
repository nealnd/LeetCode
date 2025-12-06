#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> counts;
        for (auto num : arr)
        {
            counts[num]++;
        }

        unordered_set<int> set;
        for (auto count : counts)
        {
            set.insert(count.second);
        }
        return set.size() == counts.size() ? true : false;
    }
};

int main()
{
    vector<int> arr{1, 2, 2, 1, 1, 3};
    Solution sl;
    cout << sl.uniqueOccurrences(arr);
}