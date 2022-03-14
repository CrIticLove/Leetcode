import queue
import numpy as np


class Solution:
    def getFood(self, grid: List[List[str]]) -> int:
        sp = np.shape(grid)
        startP = (0, 0)
        self.grid = np.full((sp[0]+2, sp[1]+2), 'X', dtype=str)
        for i in range(sp[0]):
            for j in range(sp[1]):
                self.grid[i+1][j+1] = grid[i][j]
                if grid[i][j] == '*':
                    startP = (i+1, j+1)
        q = queue.Queue()
        q.put((startP[0], startP[1], 0))
        while len(q):
            p = q.get()
            ch = self.grid[p[0]][p[1]]
            if ch == '#':
                return p[2]
            if ch == 'X':
                continue
            self.grid[p[0]][p[1]] = 'X'
            q.put((p[0]+1, p[1], p[2]+1))
            q.put((p[0]-1, p[1], p[2]+1))
            q.put((p[0], p[1]+1, p[2]+1))
            q.put((p[0], p[1]-1, p[2]+1))
        return -1
