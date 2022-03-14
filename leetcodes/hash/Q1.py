class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashset = dict()
        for index, n in enumerate(nums):
            if target-n not in hashset:
                hashset[n] = index
            else:
                return [hashset[target-n], index]
