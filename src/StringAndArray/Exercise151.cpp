#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int left = 0, right = 0;
        while (s[right] == ' ')
            right++;
        for (; right < s.size(); right++)
        {
            if (s[right] != ' ')
            {
                s[left] = s[right];
                left++;
            }
            else
            {
                while (s[right] == ' ')
                {
                    right++;
                }
                if (right < s.size())
                {
                    s[left] = ' ';
                    left++;
                    right--;
                }
            }
        }
        reverse(s, 0, left - 1);
        int start = 0, end = 0;
        for (; end <= left && start < left; end++)
        {
            if (s[start] != ' ' && (end == left || s[end] == ' '))
            {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }
        return s.substr(0, left);
    }

private:
    void reverse(string &s, int left, int right)
    {
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main()
{
    string s = " a  good   example ";
    Solution sl;
    cout << sl.reverseWords(s);
}