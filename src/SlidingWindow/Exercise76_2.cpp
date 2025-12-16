#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need, window;
        for (char c : t)
            need[c]++;

        int have = 0, needCount = need.size();
        int left = 0, minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];
            window[c]++;
            if (need.contains(c) && window[c] == need[c])
                have++;

            while (have == needCount)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }
                char l = s[left];
                window[l]--;
                if (need.contains(l) && window[l] < need[l])
                    have--;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main()
{
    string s = "aaaaaaaaaaaabbbbbcdd";
    string t = "abcdd";
    Solution sl;
    cout << sl.minWindow(s, t);
}