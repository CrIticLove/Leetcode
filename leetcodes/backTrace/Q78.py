class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.ans = []
        self.subset = []
        def helper(index):
            if index==len(nums):
                self.ans.append(self.subset.copy())
                return
            # put
            self.subset.append(nums[index])
            helper(index+1)
            self.subset.pop()
            helper(index+1)
            return
        helper(0)
        return self.ans