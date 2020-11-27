#include <vector>
#include <set>
using namespace std;

class Solution
{
private:
    set<vector<int>> ansSet;
    vector<int> temp;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        DFS(0, candidates, target);
        set<vector<int>>::iterator it = ansSet.begin();
        while (it != ansSet.end())
        {
            ans.push_back(*it);
            ++it;
        }
        return ans;
    }

    void DFS(int index, vector<int> &candidates, int target)
    {
        static const int len = candidates.size();
        int sum = 0;
        for (int num : temp)
        {
            sum += num;
        }
        if (sum == target)
            ansSet.insert(temp);
            temp.pop_back();
        if (index >= len)
            return;
        if (candidates[index] + sum <= target)
        {
            temp.push_back(candidates[index]);
            DFS(index, candidates, target);
            temp.pop_back();
            DFS(index + 1, candidates, target);
        }
        else
        {
            DFS(index + 1, candidates, target);
        }
    }
};
