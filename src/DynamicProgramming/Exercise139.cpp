#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        string firstWord;
        size_t index = string::npos;
        for (auto &word : wordDict)
        {
            index = s.find(word);
            if (index != string::npos)
            {
                firstWord = word;
                break;
            }
        }

        size_t left = index;
        size_t right = index + firstWord.size();
        string LeftS(s, 0, left + 1);
        string rightS(s, right - 1, s.size());
        return wordBreak(LeftS, wordDict) && wordBreak(rightS, wordDict);
    }

 
};