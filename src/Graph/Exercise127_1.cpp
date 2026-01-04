#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.contains(endWord))
            return 0;

        queue<string> q;
        unordered_set<string> seen;

        q.push(beginWord);
        seen.insert(beginWord);

        int count = 1;

        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                string cur = q.front();
                q.pop();

                if (cur == endWord)
                    return count;

                for (auto &word : wordList)
                {
                    if (!seen.contains(word) && OneCharDiff(word, cur))
                    {
                        seen.insert(word);
                        q.push(word);
                    }
                }
            }
            count++;
        }
        return 0;
    }

private:
    bool OneCharDiff(const string &a, const string &b)
    {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i] && ++diff > 1)
                return false;
        }
        return diff == 1;
    }
};
