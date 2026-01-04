#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        queue<string> q;
        unordered_map<string, bool> seen;
        bool exist = false;
        for (auto &mutation : bank)
        {
            if (mutation == endGene)
                exist = true;

            if (OneCharDiff(mutation, startGene))
            {
                q.push(mutation);
                seen[mutation] = true;
            }
        }
        if (!exist)
            return -1;
        if (q.empty())
            return -1;
        int count = 0;
        while (!q.empty())
        {
            count++;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string &top = q.front();
                q.pop();

                if (top == endGene)
                    return count;
                else
                {

                    for (auto &mutation : bank)
                    {
                        if (!seen.contains(mutation) && OneCharDiff(mutation, top))
                        {
                            seen[mutation] = true;
                            q.push(mutation);
                        }
                    }
                }
            }
        }
        if (seen.contains(endGene) && seen[endGene] == true)
            return count;
        else
            return -1;
    }

private:
    bool OneCharDiff(string &str1, string &str2)
    {
        int count = 0;
        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] != str2[i])
                count++;
        }
        return count == 1;
    }
};

int main()
{
    string startGene = "AACCGGTT", endGene = "AACCGGTA";

    vector<string> bank{"AACCGGTA"};

    Solution sl;
    cout << sl.minMutation(startGene, endGene, bank);
}