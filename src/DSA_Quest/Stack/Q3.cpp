/* Note: not master stringstream  */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> result(n, 0);
        stack<int> stamp;
        stack<int> funcID;
        for (auto log : logs)
        {
            stringstream ss(log);
            std::string part1, part2, part3;
            std::getline(ss, part1, ':');
            std::getline(ss, part2, ':');
            std::getline(ss, part3, ':');
            int a = std::stoi(part1);
            std::string b = part2;
            int c = std::stoi(part3);
            if (b == "start")
            {
                stamp.push(c);
                funcID.push(a);
            }
            else
            {
                int length = c - stamp.top() + 1;

                result[a] += length;
                stamp.pop();
                funcID.pop();
                //key part
                if (!funcID.empty())
                    result[funcID.top()] -= length;
            }
        }
        return result;
    }
};


