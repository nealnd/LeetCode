#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ans;
        int j = 0;
        for (int i = 1; i <= n; i++)
        {
            if (j < target.size())
            {
                if (target[j] == i)
                {
                    ans.push_back("Push");
                    j++;
                }
                else if (target[j] > i)
                {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
            }
            else
                break;
        }
        return ans;
    }
};

int main()
{
    vector<int> target{1, 3};
    int n = 3;
    Solution sl;
    for (auto s : sl.buildArray(target, n))
        cout << s << " ";
}