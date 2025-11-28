#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int n = s.size();
        int count = 0;
        set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < k; i++)
        {
            if (vowels.contains(s[i]))
            {
                count++;
            }
        }
        int maxcount = count;
        for (int i = k; i < n; i++)
        {
            if (vowels.contains(s[i]))
            {
                count++;
            }
            if (vowels.contains(s[i - k]))
            {
                count--;
            }
            maxcount = max(count, maxcount);
        }

        return maxcount;
    }
};