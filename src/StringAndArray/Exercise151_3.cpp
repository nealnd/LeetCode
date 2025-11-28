#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution
{
public:
    string reverseWords(string s)
    {

        reverse(s.begin(), s.end());
        int i = 0, k = 0, n = s.size();
        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++;
            if (i < n && k > 0)
            {
                s[k] = ' ';
                k++;
            }
            int start_index = k;

            while (i < n && s[i] != ' ')
            {
                s[k++] = s[i++];
            }

            reverse(s.begin() + start_index, s.begin() + k);
        }
        s.resize(k);
        return s;
    }
};

int main(){
    string s = "the sky is blue";
    Solution sl;
    cout << sl.reverseWords(s);
}