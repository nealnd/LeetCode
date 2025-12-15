/* Note:generate key by using array */

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
        unordered_map<string, vector<string>> ans;
        for (auto &s : strs)
        {
            vector<int> count(26, 0);
            for (auto c : s)
            {
                count[c - 'a']++;
            }

            /* generate key */
            string key;
            for (int num : count)
            {
                key += to_string(num);
            }

            ans[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &el : ans)
        {
            result.push_back(move(el.second));
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
