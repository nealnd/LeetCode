/* Note:not solved by myself */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        
        stack<int> st;
        vector<int> left(heights.size()), right(heights.size());
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            right[i] = st.empty() ? heights.size() : st.top();
            st.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }
};