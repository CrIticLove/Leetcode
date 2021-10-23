class Solution:
    def minDeletions(self, s: str) -> int:
        count = [0]*26
        for c in s:
            count[ord(c) - ord('a')] = count[ord(c) - ord('a')] + 1
        ans = 0
        sett = set()
        for ct in count:
            while (ct > 0) and (ct in sett):
                ct = ct - 1
                ans = ans + 1
            if ct > 0:
                sett.add(ct)
        return ans


if __name__ == '__main__':
    solution = Solution()
    print(solution.minDeletions("aaabbbccc"))
