# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        self.ans = 0
        self.distance = distance
        self.DFS(root)
        return self.ans

    def DFS(self, node: TreeNode):
        if node == None:
            return []
        if node.left == None and node.right == None:
            return [1]
        left = self.DFS(node.left)
        right = self.DFS(node.right)
        for i in left:
            for j in right:
                if i+j <= self.distance:
                    self.ans += 1
        left = [i+1 for i in left if i+1 < self.distance]
        right = [i+1 for i in right if i+1 < self.distance]
        return left+right
