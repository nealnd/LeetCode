#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int i = 0, j = 1;
        int count = 0;
        while (i < flowerbed.size() && j < flowerbed.size())
        {
            if (flowerbed[i] == 0 && flowerbed[j] == 0)
            {
                if (j > i + 1)
                {
                    flowerbed[i + 1] = 1;
                    count++;
                    i = i + 2;
                }
                j++;
            }
            else if (flowerbed[i] == 1 && flowerbed[j] == 0)
            {
                if (j > i + 2)
                {
                    flowerbed[i + 2] = 1;
                    count++;
                    i = i + 2;
                }
                else
                    j++;
            }
            else
            {
                i = j;
                j++;
            }
        }
        return count >= n;
    }
};

int main(){
    vector<int>flowerbed{1,0,0,0,1};
    Solution s;
    cout<<s.canPlaceFlowers(flowerbed,2);
}