#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int count = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] <= 'Z' && word[i] >= 'A')
            {
                count++;
            }
        }
        if (count == 1 && word[0] <= 'Z' && word[0] >= 'A')
            return true;
        if (count == 0)
            return true;
        if (count == word.size())
            return true;
        return false;
    }
};

int main()
{
    string word = "g";
    Solution sl;
    cout << sl.detectCapitalUse(word);
}