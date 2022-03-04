class Solution:
    def customSortString(self, order: str, s: str) -> str:
        count = collections.Counter(s)
        ans = ''
        for c in order:
            ans += count[c]*c
            count[c] = 0
        for key in count:
            if count[key] != 0:
                ans += key*count[key]
        return ans
