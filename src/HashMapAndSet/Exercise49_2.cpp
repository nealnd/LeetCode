#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> res;
        for (auto &s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            res[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &el : res)
        {
            result.push_back(el.second);
        }
        return result;
    }
};

int main()
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sl;
    for (auto el : sl.groupAnagrams(strs))
    {
        for (auto e : el)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}