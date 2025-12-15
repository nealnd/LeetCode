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
        vector<string> sortElem(strs);
        for (auto &el : sortElem)
        {
            sort(el.begin(), el.end());
        }
        int index = 0;
        unordered_map<string, int> map;
        vector<vector<string>> res;
        for (int i = 0; i < sortElem.size(); i++)
        {
            if (map.contains(sortElem[i]))
            {
                res[map[sortElem[i]]].push_back(strs[i]);
            }
            else
            {
                map.insert({sortElem[i], index});
                res.push_back({});
                res.back().push_back(strs[i]);
                index++;
            }
        }
        return res;
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