#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int CCount = 0, SCount = 0;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == 1)
                SCount++;
            else
                CCount++;
        }
        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (sandwiches[i] == 1)
            {
                if (SCount > 0)
                {
                    SCount--;
                }
                else
                {
                    return sandwiches.size() - i;
                }
            }
            else
            {
                if (CCount > 0)
                    CCount--;
                else
                {
                    return sandwiches.size() - i;
                }
            }
        }
        return 0;
    }
};