class Solution:
    def validPalindrome(self, s: str) -> bool:
        if len(s)==0 or len(s)==1:
            return True
        if s[0] == s[-1]:
            return self.validPalindrome(s[1:-1])
        else:
            return self.checkPalin(s[:-1]) or self.checkPalin(s[1:])
        return True

    def checkPalin(self, s:str) -> bool:
        # if len(s)==0 or len(s)==1:
        #     return True
        # return s[0] == s[-1] and self.checkPalin(s[1:-1])
        return s == s[::-1]