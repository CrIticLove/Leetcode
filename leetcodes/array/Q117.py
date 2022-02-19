class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        lenth = len(bits)
        if lenth == 1:
            return True
        pos = 0
        while True:
            if bits[pos] == 0:
                pos += 1
            else:
                pos += 2
            if pos == lenth:
                return False
            if pos == lenth-1:
                return True
