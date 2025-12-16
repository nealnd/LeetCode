/* Note:KMP */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        vector<int> matches = kmpSearch(haystack, needle);
        return matches.size() == 0 ? -1 : matches[0];
    }

private:
    vector<int> computePrefix(const string &pattern)
    {
        int m = pattern.length();
        vector<int> next(m, 0);
        int j = 0;

        for (int i = 1; i < m; i++)
        {
            while (j > 0 && pattern[i] != pattern[j])
            {
                j = next[j - 1];
            }
            if (pattern[i] == pattern[j])
            {
                j++;
            }
            next[i] = j;
        }
        return next;
    }

    vector<int> kmpSearch(const string &text, const string &pattern)
    {
        int n = text.length();
        int m = pattern.length();
        vector<int> next = computePrefix(pattern);
        vector<int> matches;

        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j > 0 && text[i] != pattern[j])
            {
                j = next[j - 1];
            }
            if (text[i] == pattern[j])
            {
                j++;
            }
            if (j == m)
            {
                matches.push_back(i - m + 1);
                j = next[j - 1];
            }
        }
        return matches;
    }
};

int main()
{
    string haystack = "abababca", needle = "abca";
    Solution sl;
    cout << sl.strStr(haystack, needle);
}