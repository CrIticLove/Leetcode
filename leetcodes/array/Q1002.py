import collections
from typing import List

class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        res = collections.Counter(words[0])
        for word in words[1:]:
            res = res & collections.Counter(word)
        return list(res.elements())
s = Solution()
s.commonChars(['leetcode'])