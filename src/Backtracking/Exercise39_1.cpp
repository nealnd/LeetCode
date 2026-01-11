/* Note: start index is key */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        SumHelper(candidates, target, ans, temp,0);
        return ans;
    }

private:
    void SumHelper(vector<int> &candidates, int target, vector<vector<int>> &ans,vector<int>&temp,int start)
    {
        if(target<0)
            return;
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }

        for (; start < candidates.size();start++){
            temp.push_back(candidates[start]);
            SumHelper(candidates, target - candidates[start], ans, temp,start);
            temp.pop_back();
        }
    }
};

int main(){
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    Solution sl;
    sl.combinationSum(candidates, target);
}