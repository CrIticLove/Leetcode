#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        const int size1 = nums1.size(), size2 = nums2.size();
        vector<int> tempVec1, tempVec2, merged, ans;
        for (int i = 0; i <= k; ++i)
        {
            if (i > size1 || k - i > size2)
                continue;
            tempVec1 = findNMax(nums1, i);
            tempVec2 = findNMax(nums2, k - i);

            // merge two vec together to get the largest vec
            merged = merge(tempVec1, tempVec2, k);
            ans = comp(ans, merged, k) ? ans : merged;
        }
        return ans;
    }

    // 沿用402的代码，做些许改动
    vector<int> findNMax(vector<int> &num, int k)
    {
        const int kk = k;
        const int len = num.size();
        k = len - k;
        vector<int> ans;
        int j;
        for (int i = 0; i < len; ++i)
        {
            j = ans.size() - 1;
            while (j >= 0 && k > 0)
            {
                if (ans[j] < num[i])
                {
                    ans.pop_back();
                    --j;
                    --k;
                    continue;
                }
                break;
            }
            ans.push_back(num[i]);
        }
        while (ans.size() > kk)
        {
            ans.pop_back();
        }
        return ans;
    }

    // merge two vec together to get the largest vec
    vector<int> merge(vector<int> &vec1, vector<int> &vec2, int k)
    {
        vector<int> ans;
        int index1 = 0, index2 = 0, counter;
        bool winner1 = true;
        while (ans.size() <= k)
        {
            // if only vec2
            if (index1 >= vec1.size())
            {
                for (; index2 < vec2.size(); ++index2)
                {
                    ans.push_back(vec2[index2]);
                }
                return ans;
            }
            // if only vec1
            if (index2 >= vec2.size())
            {
                for (; index1 < vec1.size(); ++index1)
                {
                    ans.push_back(vec1[index1]);
                }
                return ans;
            }

            // compare
            if (vec1[index1] > vec2[index2])
            {
                ans.push_back(vec1[index1]);
                ++index1;
            }
            else if (vec1[index1] < vec2[index2])
            {
                ans.push_back(vec2[index2]);
                ++index2;
            }
            else
            {
                // vec1[index1] == vec2[index2]
                counter = 1;
                while (index1 + counter <= vec1.size() && index2 + counter <= vec2.size())
                {
                    if (index1 + counter >= vec1.size())
                    {
                        winner1 = false;
                        break;
                    }
                    else if (index2 + counter >= vec2.size())
                    {
                        winner1 = true;
                        break;
                    }
                    else if (vec1[index1 + counter] > vec2[index2 + counter])
                    {
                        winner1 = true;
                        break;
                    }
                    else if (vec1[index1 + counter] < vec2[index2 + counter])
                    {
                        winner1 = false;
                        break;
                    }
                    ++counter;
                }
                if (winner1)
                {
                    ans.push_back(vec1[index1]);
                    ++index1;
                }
                else
                {
                    ans.push_back(vec2[index2]);
                    ++index2;
                }
            }
        }
        return ans;
    }

    // compare funciton
    bool comp(vector<int> &vec1, vector<int> &vec2, int k)
    {
        if (vec1.empty())
            return false;
        if (vec2.empty())
            return true;
        for (int i = 0; i < k; ++i)
        {
            if (vec1[i] > vec2[i])
            {
                return true;
            }
            else if (vec1[i] < vec2[i])
            {
                return false;
            }
        }
        return true;
    }
};
