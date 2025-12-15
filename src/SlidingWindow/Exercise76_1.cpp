#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.length() < t.length())
            return "";

        vector<int> map(128, 0);
        int count = t.length();
        int start = 0, minStart = 0, minLen = INT_MAX;
        for (auto c : t)
            map[c]++;
        for (int end = 0; end < s.length(); end++)
        {
            if (map[s[end]] > 0)
            {
                count--;
            }
            map[s[end]]--;
            while (count == 0)
            {
                if (end - start + 1 < minLen)
                {
                    minStart = start;
                    minLen = end - start + 1;
                }

                if (map[s[start]] == 0)
                    count++;
                map[s[start]]++;
                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sl;
    cout << sl.minWindow(s, t);
}