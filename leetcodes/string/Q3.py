class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        alphaSet=set()
        left = 0
        right = 0
        while left <= right and right < len(s):
            right = right + 1
            if s[right - 1] not in alphaSet:
                alphaSet.add(s[right - 1])
                ans = max(ans, right - left)
            else:
                while s[left]!=s[right - 1]:
                    alphaSet.remove(s[left])
                    left = left+1
                ans = max(ans, right - left)
        return ans
