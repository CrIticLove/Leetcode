#include <vector>
#include <unordered_map>
using namespace std;

// 使用一个hashmap
class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        const int n = A.size();
        if (n == 0)
            return 0;
        unordered_map<int, int> map1;
        unordered_map<int, int>::iterator temp;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                temp = map1.find(A[i] + B[j]);
                if (temp != map1.end())
                {
                    ++temp->second;
                }
                else
                {
                    map1.insert(make_pair(A[i] + B[j], 1));
                }
            }
        }
        // find
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                temp = map1.find(-C[i] - D[j]);
                if (temp != map1.end())
                {
                    ans += temp->second;
                }
            }
        }
        return ans;
    }
};

// 使用了两个hashmap
class Solution1
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        const int n = A.size();
        if (n == 0)
            return 0;
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        unordered_map<int, int>::iterator temp;
        unordered_map<int, int>::iterator temp2;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp = map1.find(A[i] + B[j]);
                if (temp != map1.end())
                {
                    ++temp->second;
                }
                else
                {
                    map1.insert(make_pair(A[i] + B[j], 1));
                }
                temp = map2.find(C[i] + D[j]);
                if (temp != map2.end())
                {
                    ++temp->second;
                }
                else
                {
                    map2.insert(make_pair(C[i] + D[j], 1));
                }
            }
        }
        temp = map1.begin();
        while (temp != map1.end())
        {
            temp2 = map2.find(-temp->first);
            if (temp2 != map2.end())
            {
                ans += temp->second * temp2->second;
            }
            ++temp;
        }
        return ans;
    }
};
