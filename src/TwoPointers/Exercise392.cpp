#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
       int n1 = s.size();
        int n2 = t.size();
        if (n1 == 0)
            return true;
        int i = 0, j = 0;
        while (i < n1 && j < n2) {

            if (s[i] == t[j]) {
                if (i == n1 - 1 && j <= n2 - 1) {
                    return true;
                }
                i++;
                j++;
            } else {
                j++;
            }
        }
        return false;
    }
    
};

int main(){
    string s = "abc", t = "ahbgdc";
    Solution sl;
    cout << sl.isSubsequence(s, t);
}