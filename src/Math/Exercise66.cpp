#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {

            int total = digits[i] + carry;
            digits[i] = total % 10;
            carry = total / 10;
            if (carry == 0)
                break;
        }
        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};