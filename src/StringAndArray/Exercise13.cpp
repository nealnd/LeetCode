#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {

        unordered_map<char, int> Data{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (i - 1 >= 0 && Data[s[i - 1]] < Data[s[i]])
            {
                res -= Data[s[i - 1]];
                res += Data[s[i]];
                i--;
            }
            else
            {
                res += Data[s[i]];
            }
        }
        return res;
    }
};

int main()
{
    string s("MCMXCIV");
    Solution sl;
    cout << sl.romanToInt(s);
}