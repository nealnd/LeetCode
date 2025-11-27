#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {

        int Max = 0;
        for (auto candy : candies)
        {
            if (candy > Max)
                Max = candy;
        }

        vector<bool> temp;
        for (auto candy : candies)
        {
            if (candy >= Max - extraCandies)
            {
                temp.push_back(true);
            }
            else
                temp.push_back(false);
        }
        return temp;
    }
};

int main(){
    vector<int>candies{2,3,5,1,3};
    int extraCandies=3;

    Solution s;
    for(auto temp:s.kidsWithCandies(candies,extraCandies)){
        cout<<temp<<" ";
    }
}