from typing import List


def solution(matrix:List[str]):
    return sum([max(z) for z in zip(*[sorted([int(j) for j in i], reverse=True) for i in matrix])])

m = ['712', '246', '365', '312']

solution(m)