class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        di = dict()
        for s in strs:
            tp = ''.join(sorted(s))
            if tp not in di:
                di[tp] = []
            di[tp].append(s)
        ans = []
        for a in di.values():
            ans.append(a)
        return ans
