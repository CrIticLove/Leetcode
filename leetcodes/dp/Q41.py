class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        leftMax = [0] * len(height)
        rightMax = [0] * len(height)
        for i in range(1, len(height)):
            leftMax[i] = max(leftMax[i-1], height[i-1])
        for i in range(len(height)-2, -1, -1):
            rightMax[i] = max(rightMax[i+1], height[i+1])
        
        for i in range(len(height)):
            ans = ans + max((min(leftMax[i], rightMax[i]) - height[i]), 0)
        return ans
