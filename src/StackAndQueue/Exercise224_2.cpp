/* Note: diving into a new context where the sign can change based on what came before it */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int ans = 0;
        long long num = 0;
        int sign = 1;
        stack<int> stack{{sign}};
        for (const char c : s)
            if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (c == '(')
                stack.push(sign);
            else if (c == ')')
                stack.pop();
            else if (c == '+' || c == '-')
            {
                ans += sign * num;
                sign = (c == '+' ? 1 : -1) * stack.top();
                num = 0;
            }
        return ans + sign * num;
    }
};

int main()
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    Solution sl;
    cout << sl.calculate(s);
}