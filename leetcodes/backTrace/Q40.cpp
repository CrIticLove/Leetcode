#include <vector>
#include <set>
using namespace std;

class Solution
{
private:
    set<vector<int>> set;
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> tempsort;

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        if (target == 0)
            return ans;
        DFS(0, candidates, target);
        std::set<vector<int>>::iterator it = set.begin();
        while (it != set.end())
        {
            ans.push_back(*it);
            ++it;
        }
        return ans;
    }

    void DFS(int index, vector<int> &candidates, const int &target)
    {
        if (index >= candidates.size())
            return;
        if (candidates[index] == target)
        {
            temp.push_back(candidates[index]);
            tempsort = temp;
            sort(tempsort.begin(), tempsort.end());
            set.insert(tempsort);
            temp.pop_back();
            DFS(index + 1, candidates, target);
            return;
        }
        if (candidates[index] < target)
        {
            temp.push_back(candidates[index]);
            DFS(index + 1, candidates, target - candidates[index]);
            temp.pop_back();
            DFS(index + 1, candidates, target);
            return;
        }
        if (candidates[index] > target)
        {
            DFS(index + 1, candidates, target);
            return;
        }
    }
};
