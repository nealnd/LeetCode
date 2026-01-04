#include <iostream>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;
        int left = 0, right = x;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (mid > x / mid)
            {
                right = mid - 1;
            }
            else if (mid < x / mid)
            {
                left = mid + 1;
            }
            else
                return mid;
        }
        return left * left > x ? left - 1 : left;
    }
};

int main(){
    int x = 2147395599;
    Solution sl;
    cout << sl.mySqrt(x);
}