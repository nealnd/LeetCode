#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> map;

        for (auto ch : s)
            map[ch]++;

        for (auto ch : t)
        {
            if (!map.contains(ch) || map[ch] == 0)
                return false;
            map[ch]--;
        }
        return true;
    }
};

int main()
{
    string s = "anagram";
    string t = "nagaram";

    Solution sl;
    cout << sl.isAnagram(s, t);
}