/* Note: not solved by myself */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp;

        helper(n, 0, 0, ans, temp);
        return ans;
    }

private:
    void helper(int n, int left, int right, vector<string> &ans, string &temp)
    {

        if (left == n && right == n && temp.size() == 2 * n)
        {
            ans.push_back(temp);
            return;
        }

        if (left < n)
        {
            temp += '(';
            helper(n, left + 1, right, ans, temp);
            temp.pop_back();
        }

        if (right < left)
        {
            temp += ')';
            helper(n, left, right + 1, ans, temp);
            temp.pop_back();
        }
    }
};

int main()
{
    int n = 3;
    Solution sl;
    sl.generateParenthesis(n);
}