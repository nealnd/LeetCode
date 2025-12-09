#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.size() - 1;
        while (i >= 0)
        {
            if (s[i] == ' ')
                i--;
            else
                break;
        }

        int j = i - 1;
        while (j >= 0 && s[j] != ' ')
        {
            j--;
        }
        return i - j;
    }
};

int main()
{
    string s = "day";
    Solution sl;
    cout << sl.lengthOfLastWord(s);
}