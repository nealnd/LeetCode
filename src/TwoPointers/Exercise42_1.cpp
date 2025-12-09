#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int start = 0;
        int end = 0;
        int tempRightWater = 0;
        int RightWater = 0;
        int LeftWater = 0;
        int tempLeftWater = 0;
        for (end = start + 1; end < height.size(); end++)
        {
            if (height[end] < height[start])
            {
                tempRightWater += height[start] - height[end];
            }
            else
            {
                RightWater = tempRightWater;
                start = end;
            }
        }

        if (height[start] > height[end - 1])
        {
            int i = height.size() - 1;

            for (int j = i - 1; j >= start; j--)
            {
                if (height[j] < height[i])
                {
                    tempLeftWater += height[i] - height[j];
                }
                else
                {
                    LeftWater = tempLeftWater;
                    i = j;
                }
            }
        }
        return RightWater + LeftWater;
    }
};

int main()
{
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sl;
    cout << sl.trap(height);
}