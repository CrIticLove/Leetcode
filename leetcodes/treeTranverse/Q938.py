# Definition for a binary tree node.
from turtle import left
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        # use DFS may be better
        self.ans = 0

        def DFS(node: Optional[TreeNode]):
            if not node:
                return
            DFS(node.left)
            DFS(node.right)
            if not(node.val > high or node.val < low):
                self.ans += node.val

        DFS(root)
        return self.ans
