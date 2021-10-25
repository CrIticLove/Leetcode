from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        se = set(nums)
        for n in se:
            accu = 1
            num = n
            if (num-1) not in se:
                while (num+1) in se:
                    accu = accu + 1
                    num += 1
                ans = max(ans, accu)
        return ans
