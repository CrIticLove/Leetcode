class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stk = []
        for index, c in enumerate(s):
            if c == '(':
                stk.append(index)
            if c == ')':
                if len(stk) == 0:
                    stk.append(index)
                    continue
                if s[stk[-1]] == '(':
                    stk.pop()
                else:
                    stk.append(index)
        ans = ''
        num = 0
        for index, c in enumerate(s):
            if num == len(stk):
                ans += c
                continue
            if index == stk[num]:
                num += 1
            else:
                ans += c
        return ans