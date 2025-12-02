#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        return vector<vector<int>>{getDifferenceInFirstArray(nums1, nums2), getDifferenceInFirstArray(nums2, nums1)};
      }

    private:
    vector<int>getDifferenceInFirstArray(vector<int>&nums1,vector<int>&nums2){
        unordered_set<int> set1, set2;
        for (auto i : nums2)
            set2.insert(i);

        for (auto num : nums1)
        {
            if (set2.find(num) == set2.end())
            {
                set1.insert(num);
            }
        }
        return vector<int>(set1.begin(), set1.end());
    }
};

int main(){
    vector<int> nums1{-3, 6, -5, 4, 5, 5};
    vector<int> nums2{6, 6, -3, -3, 3, 5};
    Solution sl;
    vector<vector<int>> vec(sl.findDifference(nums1, nums2));
    for(auto v:vec){
        for(auto num:v)
        {
            cout << num <<" ";
        }
        cout << endl;
    }

}