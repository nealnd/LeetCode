#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int maxAltitude = 0;
        int sum = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            sum+=gain[i];
            maxAltitude = max(maxAltitude, sum);
        }
        return maxAltitude;
    }
};

int main(){
    vector<int> gain{-5, 1, 5, 0, -7};
    Solution sl;
    cout << sl.largestAltitude(gain);
}

