/* Note: a better method */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        std::vector<int> alphabet(26, 0);
        for (char c : ransomNote)
        {
            size_t i = magazine.find(c, alphabet[c - 'a']);
            if (i == std::string::npos)
                return false;
            alphabet[c - 'a'] = i + 1;
        }
        return true;
    }
};

int main()
{
    string ransomNote = "aa";
    string magazine = "aba";
    Solution sl;
    cout << sl.canConstruct(ransomNote, magazine);
}