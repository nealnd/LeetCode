/* Note： If a character and a word are not appearing together for the first time, their previous occurrence positions must be the same.
We use i + 1 instead of i to distinguish between “never seen before” (0) and “first seen at index 0.” */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, int> lastPatternIndex;
        unordered_map<string, int> lastWordIndex;

        istringstream stream(s);
        int index = 0;

        for (string word; stream >> word; ++index)
        {

            if (index >= pattern.size())
                return false;

            char p = pattern[index];

            int prevPatternPos = lastPatternIndex[p];
            int prevWordPos = lastWordIndex[word];

            if (prevPatternPos != prevWordPos)
                return false;

            lastPatternIndex[p] = index + 1;
            lastWordIndex[word] = index + 1;
        }

        return index == pattern.size();
    }
};

int main()
{
    string pattern("abba");
    string s("dog cat cat dog");
    Solution sl;
    cout << sl.wordPattern(pattern, s);
}
