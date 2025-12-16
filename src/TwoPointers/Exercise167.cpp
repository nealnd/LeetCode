#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;
        while (i < j)
        {
            if (numbers[i] + numbers[j] > target)
                j--;
            else if (numbers[i] + numbers[j] < target)
                i++;
            else
            {
                return vector<int>{i + 1, j + 1};
            }
        }
        return vector<int>{};
    }
};

int main()
{
    vector<int> numbers{2, 7, 11, 15};
    Solution sl;
    for (auto num : sl.twoSum(numbers, 9))
    {
        cout << num << endl;
    }
}