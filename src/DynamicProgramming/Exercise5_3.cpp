/* Note: a better method, O(n),Manacher's algorithm */

#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        // Edge case: empty or single-character string is already a palindrome
        if (s.length() <= 1)
        {
            return s;
        }

        int maxLen = 1;
        std::string maxStr = s.substr(0, 1);

        /*
            Preprocess the string for Manacher's Algorithm.

            Example:
            Original:  "abba"
            After transform: "#a#b#b#a#"

            Purpose:
            1. Unify odd-length and even-length palindromes
            2. Ensure every palindrome has a single center
        */
        s = std::regex_replace(s, std::regex(""), "#");

        /*
            dp[i] represents:
            -----------------
            The RADIUS of the palindrome centered at index i
            in the TRANSFORMED string s.

            More precisely:
            dp[i] = maximum k such that
            s[i - k ... i + k] is a palindrome

            So the full palindrome length is:
            2 * dp[i] + 1
        */
        std::vector<int> dp(s.length(), 0);
        int center = 0;
        int right = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            /*
                If i is inside the current known palindrome (i < right),
                we can use symmetry to initialize dp[i].

                mirror = 2 * center - i
                mirror is the symmetric position of i with respect to center.
                right - i is how much space remains before hitting the known boundary
            */
            if (i < right)
            {

                dp[i] = std::min(right - i, dp[2 * center - i]);
            }
            /*
                Try to expand the palindrome centered at i.

                i - dp[i] - 1 : the next character to the LEFT to check
                i + dp[i] + 1 : the next character to the RIGHT to check

                We expand as long as:
                1. We stay inside the string bounds
                2. The characters on both sides are equal
            */

            while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length() && s[i - dp[i] - 1] == s[i + dp[i] + 1])
            {
                dp[i]++;
            }

            /*
                If the palindrome centered at i extends beyond the current right boundary,
                update center and right.
            */
            if (i + dp[i] > right)
            {
                center = i;
                right = i + dp[i];
            }
            /*
                If we found a longer palindrome than before,
                extract it from the transformed string,
                then remove '#' characters to recover the original substring.
            */
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);
                maxStr.erase(std::remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
            }
        }

        return maxStr;
    }
};

int main()
{
    string s = "babad";
    Solution sl;
    cout << sl.longestPalindrome(s);
}