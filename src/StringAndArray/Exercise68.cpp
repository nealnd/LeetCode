#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<int> divideIndex;
        divideIndex.push_back(-1);
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            count += words[i].size();
            if (count > maxWidth)
            {
                count = 0;
                divideIndex.push_back(i - 1);
                i--;
            }
            else
                // at least one " "
                count += 1;
        }
        int index = divideIndex.back();
        int n = words.size() - 1;
        if (index < n - 1)
            divideIndex.push_back(words.size() - 1);

        vector<string> res;
        for (int i = 0; i < divideIndex.size() - 1; i++)
        {
            addSpace(words, divideIndex[i] + 1, divideIndex[i + 1], maxWidth);
            string temp;
            for (int j = divideIndex[i] + 1; j <= divideIndex[i + 1]; j++)
            {
                temp += words[j];
            }
            res.push_back(temp);
        }

        return res;
    }

private:
    int stringLength(vector<string> &words, int left, int right)
    {
        int totalLength = 0;
        for (; left <= right; left++)
        {
            totalLength += words[left].size();
        }
        return totalLength;
    }

    void addSpace(vector<string> &words, int left, int right, int maxWidth)
    {
        int totalLength = stringLength(words, left, right);
        int i = (maxWidth - totalLength) / (right - left > 0 ? right - left : 1);
        int j = (maxWidth - totalLength) % (right - left > 0 ? right - left : 1);
        if (right != words.size() - 1)
        {
            if (left < right)
            {
                for (int k = left; k < right; k++)
                {
                    if (k - left < j)
                    {
                        string temp(i + 1, ' ');
                        words[k] += temp;
                    }
                    else
                    {
                        string temp(i, ' ');
                        words[k] += temp;
                    }
                }
            }
            else
            {

                string temp(maxWidth - totalLength, ' ');
                words[right] += temp;
            }
        }
        else
        {
            if (left < right)
            {
                int Remant = maxWidth - totalLength;
                for (int k = left; k <= right && Remant > 0; k++)
                {
                    words[k] += " ";
                    Remant--;
                }
                if (Remant >= 0)
                {
                    string temp(Remant, ' ');
                    words[right] += temp;
                }
            }
            else
            {
                string temp(maxWidth - totalLength, ' ');
                words[right] += temp;
            }
        }
    }
};

int main()

{
    vector<string> words{"a"};
    Solution sl;
    vector<string> s = sl.fullJustify(words, 1);
}