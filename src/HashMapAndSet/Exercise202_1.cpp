#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> set;
        int sum = 0;
        while (true)
        {
            while (n > 0)
            {
                int x = n % 10;
                sum += x * x;
                n = n / 10;
            }
            if (sum == 1)
                return true;
            else if (set.contains(sum))
                return false;
            else
            {
                set.insert(sum);
                n = sum;
                sum = 0;
            }
        }
    }
};

int main()
{
    int n = 19;
    Solution sl;
    cout << sl.isHappy(n) << endl;
}