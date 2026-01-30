#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> nums;
        for (auto token : tokens)
        {
            if (token != "+" && token != "-" && token != "*" && token != "/")
            {
                nums.push(stoi(token));
            }
            else
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                int num;
                if (token == "+")
                    num = num1 + num2;
                else if (token == "-")
                    num = num2 - num1;
                else if (token == "*")
                    num = num1 * num2;
                else
                    num = num2 / num1;

                nums.push(num);
            }
        }
        return nums.top();
    }
};

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution sl;
    cout << sl.evalRPN(tokens);
}