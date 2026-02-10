#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (auto stone : stones)
        {
            pq.push(stone);
        }
        while (pq.size() >= 2)
        {
            int heavy = pq.top();
            pq.pop();
            int light = pq.top();
            pq.pop();
            if (heavy - light > 0)
                pq.push(heavy - light);
        }
        return pq.empty() ? 0 : pq.top();
    }
};