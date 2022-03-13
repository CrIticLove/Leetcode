import numpy as np


class Solution_exceed:
    def getMaxLen(self, nums: List[int]) -> int:
        length = len(nums)
        dp = np.zeros((length, length), dtype=int)
        for index, num in enumerate(nums):
            dp[0][index] = 0 if num == 0 else (1 if num > 0 else -1)
        for i in range(1, length):
            for j in range(0, length-i):
                dp[i][j] = 0 if (dp[i-1,
                                    j] == 0 or nums[i+j] == 0) else (1 if nums[i+j]*dp[i-1, j] > 0 else -1)
        for i in range(length-1, -1, -1):
            ar = dp[i]
            if 1 in ar:
                return i+1
        return 0


class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        pos = [0] * len(nums)
        neg = [0]*len(nums)
        if nums[0] > 0:
            pos[0] = 1
        if nums[0] < 0:
            neg[0] = 1
        ans = pos[0]
        for i in range(1, len(nums)):
            if nums[i] > 0:
                pos[i] = pos[i-1]+1
                neg[i] = neg[i-1]+1 if neg[i-1] > 0 else 0
            if nums[i] < 0:
                pos[i] = neg[i-1]+1 if neg[i-1] > 0 else 0
                neg[i] = pos[i-1]+1
            ans = max(ans, pos[i])
        return ans
