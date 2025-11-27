#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int count=0;
        for (int i = 0; i < flowerbed.size(); i = i + 1)
        {

            if (flowerbed[i] == 0)
            {
                bool left = (i == 0 || flowerbed[i - 1] == 0);
                bool right = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);
                if (left && right )
                {
                    flowerbed[i]=1;
                    count++;
                }
            }
        }
        return count>=n;
    }
};

int main(){
    vector<int>flowerbed{1,0,0,0,1};
    Solution s;
    cout<<s.canPlaceFlowers(flowerbed,2);
}