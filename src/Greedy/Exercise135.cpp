#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> Result(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; i++)
        {
            if (ratings[i] < ratings[i + 1])
                Result[i + 1] = Result[i] + 1;
        }

        for (int i = ratings.size() - 1; i >= 1; i--)
        {
            if (ratings[i] < ratings[i - 1])
                Result[i - 1] = max(Result[i - 1], Result[i] + 1);
        }
        int count = 0;
        for (auto num : Result)
        {
            count += num;
        }
        return count;
    }
};

int main()
{
    vector<int> ratings{1, 2, 2};
    Solution sl;
    cout << sl.candy(ratings);
}