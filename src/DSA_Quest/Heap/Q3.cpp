/* Note: not solved by myself, TLE */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        priority_queue<int> pq;
        long long sum = 0;
        for (auto t : target)
        {
            pq.push(t);
            sum += t;
        }
        while (pq.top() > 1)
        {
            long long top = pq.top();
            pq.pop();
            long long rem = sum - top;
            if (rem >= top || rem <= 0)
                return false;
            long long prev = top % rem; // use % and not -, it prevents from tle due to repeated checks
            if (prev == 0)
            {
                prev = rem;
            }
            pq.push(prev);
            sum = prev + rem;
        }
        return true;
    }
};

int main()
{
    vector<int> target{1, 1000000000};
    Solution sl;
    cout << sl.isPossible(target);
}