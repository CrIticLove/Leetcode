from collections import deque

from pandas import array


class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        heightest = heights[-1]
        ans = deque()
        ans.append(len(heights)-1)
        for i in range(len(heights)-2, -1, -1):
            if heights[i]>heightest:
                ans.appendleft(i)
                heightest = heights[i]
        return ans
