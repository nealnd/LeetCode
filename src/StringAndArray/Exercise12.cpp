
/* Note: not come up with this better method */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string res;
        for (auto data : valueSymbols)
        {
            while (num >= data.first)
            {
                res += data.second;
                num -= data.first;
            }
        }
        return res;
    }
};

int main()
{
    int num = 1994;
    Solution sl;
    cout << sl.intToRoman(num);
}