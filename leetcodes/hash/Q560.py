class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sumMap = dict()
        ans = 0
        sumMap[0] = 1
        sum = 0
        remain = k
        for i in nums:
            sum += i
            remain -= i
            if sum-k in sumMap:
                ans += sumMap[sum-k]
            if not sumMap.get(sum):
                sumMap[sum] = 0
            sumMap[sum]+=1
        return ans
