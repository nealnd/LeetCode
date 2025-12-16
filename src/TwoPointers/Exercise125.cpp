#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, n = s.size() - 1;
        int j = n;
        while (i < j)
        {
            while (!isalnum(s[i]) && i < j)
                i++;
            while (!isalnum(s[j]) && i < j)
                j--;
            if (tolower(s[i]) == tolower(s[j]))
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";
    Solution sl;
    cout << sl.isPalindrome(s);
}