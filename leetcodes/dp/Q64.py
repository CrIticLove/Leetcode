class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp = [0]*len(grid[0])
        dp[0] = grid[0][0]
        for i in range(1, len(dp)):
            dp[i] = grid[0][i]+dp[i-1]
        for i in range(1, len(grid)):
            dp1 = [0]*len(grid[0])
            dp1[0] = dp[0]+grid[i][0]
            for j in range(1, len(dp)):
                dp1[j] = min(dp1[j-1], dp[j])+grid[i][j]
            dp = dp[1]
        return dp[-1]
