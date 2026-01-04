/* Note:not solved by meself, binary exponentiation */
#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }

        double result = 1;
        while (N > 0)
        {
            /*    If N is odd (the lowest binary bit is 1), the current power of x should be included in the result */
            if ((N & 1) == 1)
            {
                result *= x;
            }
            x *= x;
            N >>= 1; // divide exponent by 2
        }
        return result;
    }
};

int main()
{
    double x = 2;
    int n = -200000000;
    Solution sl;
    cout << sl.myPow(x, n);
}
