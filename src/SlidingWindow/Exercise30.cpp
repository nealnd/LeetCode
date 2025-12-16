#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> data;
        for (auto word : words)
        {
            data[word]++;
        }
        int length = words[0].size();

        vector<int> res;
        for (int offset = 0; offset < length; offset++)
        {
            int start = offset;
            unordered_map<string, int> temp;
            for (int end = length + offset; end <= s.size(); end += length)
            {
                string currentString = s.substr(end - length, length);
                if (data.contains(currentString))
                {
                    temp[currentString]++;
                    while (temp[currentString] > data[currentString])
                    {
                        temp[s.substr(start, length)]--;
                        if (temp[s.substr(start, length)] <= 0)
                            temp.erase(s.substr(start, length));
                        start += length;
                    }
                    if (temp.size() == data.size() && end - start == words.size() * length)
                    {
                        res.push_back(start);
                    }
                }
                else
                {
                    start = end;
                    temp.clear();
                }
            }
        }
        return res;
    }
};

int main()
{
    string s = "dddddddddddd";
    vector<string> words = {"dddd", "dddd"};
    Solution sl;
    sl.findSubstring(s, words);
}