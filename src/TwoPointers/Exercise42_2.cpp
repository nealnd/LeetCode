#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        int left = 0, right = n - 1;
        int lMax = 0, rMax = 0;
        int res = 0;

        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= lMax)
                {
                    lMax = height[left];
                }
                else
                {
                    res += lMax - height[left];
                }
                left++;
            }
            else
            { // height[right] < height[left]
                if (height[right] >= rMax)
                {
                    rMax = height[right];
                }
                else
                {
                    res += rMax - height[right];
                }
                right--;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sl;
    cout << sl.trap(height);
}