#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<vector<char>> m(8);
        m[0] = {'a', 'b', 'c'};
        m[1] = {'d', 'e', 'f'};
        m[2] = {'g', 'h', 'i'};
        m[3] = {'j', 'k', 'l'};
        m[4] = {'m', 'n', 'o'};
        m[5] = {'p', 'q', 'r', 's'};
        m[6] = {'t', 'u', 'v'};
        m[7] = {'w', 'x', 'y', 'z'};

        vector<string> ans;
        string temp;
        letterCombinationsHelper(digits, 0, ans, m, temp);
        return ans;
    }

private:
    void letterCombinationsHelper(string &digits, int index, vector<string> &ans, vector<vector<char>> &m,string& temp)
    {
        if (index == digits.size())
            {
                ans.push_back(temp);
                return;
            }
            
            int d = digits[index] - '0' - 2;

            for (char c : m[d])

            {
                temp.push_back(c);
                letterCombinationsHelper(digits, index + 1, ans, m, temp);
                temp.pop_back();
            }
            
    }
};

int main(){
    string digits = "23";
    Solution sl;
    for(auto s:sl.letterCombinations(digits))
        cout << s << " ";
}