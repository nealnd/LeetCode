#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {

        if (str1 + str2 != str2 + str1)
            return "";

        auto gcd = [](int len1, int len2)
        {
            int minLength = min(len1, len2);
            for (int i = minLength; i > 0; i--)
            {
                if (len1 % i == 0 && len2 % i == 0)
                {
                    return i;
                }
            }
           return 1;
        };
        int lenthGCD = gcd(str1.length(), str2.length());
        return str1.substr(0, lenthGCD);
    }
};

int main()
{
    Solution sol;
    string str1 = "ABABABAB";
    string str2 = "ABAB";
    cout << sol.gcdOfStrings(str1, str2) << endl;
    return 0;
}