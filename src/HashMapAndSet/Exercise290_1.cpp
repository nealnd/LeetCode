#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        istringstream iss(s);
        vector<string> words;
        string word;

        while (iss >> word)
        {
            words.push_back(word);
        }
        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> map;
        unordered_set<string> set;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (map.contains(pattern[i]))
            {
                if (map[pattern[i]] != words[i])
                    return false;
            }
            else
            {
                if (set.contains(words[i]))
                    return false;

                set.insert(words[i]);
                map.insert({pattern[i], words[i]});
            }
        }
        return true;
    }
};

int main()
{
    string pattern("abba");
    string s("dog cat cat dog");
    Solution sl;
    cout << sl.wordPattern(pattern, s);
}