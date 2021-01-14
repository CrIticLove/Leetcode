from typing import List

print("Hello world")
class Solution:
    def matrixScore(self, A: List[List[int]]) -> int:
        height, width = len(A), len(A[0])
        if width == 0:
            return height
        answer = height * pow(2, (width - 1))
        for j in range(1, width):
            counter = [0, 0]
            for i in range(height):
                counter[(A[i][j] + A[i][0]) % 2] += 1
            answer += max(counter) * pow(2, (width - 1 - j))
        return answer
