class Solution:
    def trap(self, height: List[int]) -> int:
        leftHigh = [0]
        for i in range(1, len(height)):
            leftHigh.append(max(leftHigh[-1], height[i-1]))
        rightHigh = [0]
        for i in range(len(height)-2, -1, -1):
            rightHigh.append(max(rightHigh[-1], height[i+1]))
        rightHigh.reverse()
        ans = 0
        for i in range(len(leftHigh)):
            ht = min(leftHigh[i], rightHigh[i])
            if ht-height[i] > 0:
                ans += ht-height[i]
        return ans
        