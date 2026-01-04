/* Note: a better way */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        int steps = 1;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                string word = q.front();
                q.pop();
                if (word == endWord)
                    return steps;

                for (int i = 0; i < word.size(); i++)
                {
                    char old = word[i];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (c == old)
                            continue;
                        word[i] = c;

                        if (dict.count(word))
                        {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = old;
                }
            }
            steps++;
        }
        return 0;
    }
};