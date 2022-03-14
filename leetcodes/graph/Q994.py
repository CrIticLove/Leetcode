from queue import Queue
import numpy as np


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        sp = np.shape(grid)
        gd = np.full((sp[0]+2, sp[1]+2), 0, dtype=int)
        rotQ = Queue()
        for i in range(sp[0]):
            for j in range(sp[1]):
                gd[i+1][j+1] = grid[i][j]
                if grid[i][j] == 2:
                    rotQ.put((i+1, j+1, 0))
        ans = 0
        while rotQ.qsize():
            g = rotQ.get()
            ans = g[2]
            if gd[g[0]+1][g[1]] == 1:
                gd[g[0]+1][g[1]] = 2
                rotQ.put((g[0]+1, g[1], g[2]+1))
            if gd[g[0]-1][g[1]] == 1:
                gd[g[0]-1][g[1]] = 2
                rotQ.put((g[0]-1, g[1], g[2]+1))
            if gd[g[0]][g[1]+1] == 1:
                gd[g[0]][g[1]+1] = 2
                rotQ.put((g[0], g[1]+1, g[2]+1))
            if gd[g[0]][g[1]-1] == 1:
                gd[g[0]][g[1]-1] = 2
                rotQ.put((g[0], g[1]-1, g[2]+1))
        for i in gd:
            if 1 in i:
                return -1
        return ans
