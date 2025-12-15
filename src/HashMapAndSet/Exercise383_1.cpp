#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> map;
        for (auto ch : magazine)
            map[ch]++;

        for (auto r : ransomNote)
        {
            if (map.contains(r))
            {
                map[r]--;
                if (map[r] < 0)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    string ransomNote = "ba";
    string magazine = "abb";
    Solution sl;
    cout << sl.canConstruct(ransomNote, magazine);
}