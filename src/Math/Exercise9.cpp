/* Note: reverse a number */

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        int reverse = 0;
        int y = x;
        while (y > 0)
        {
            reverse = reverse * 10 + y % 10;
            y /= 10;
        }
        return reverse == x;
    }
};