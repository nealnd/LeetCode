#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        return judgeIsomorphic(s, t) && judgeIsomorphic(t, s);
    }

private:
    bool judgeIsomorphic(string &s, string &t)
    {
        unordered_map<char, char> map;
        for (int i = 0; i < s.length(); i++)
        {
            if (map.contains(s[i]))
            {
                if (map[s[i]] != t[i])
                    return false;
            }
            else
            {
                map.insert({s[i], t[i]});
            }
        }
        return true;
    }
};

int main()
{
    string s = "paper";
    string t = "title";
    Solution sl;
    cout << sl.isIsomorphic(s, t);
}