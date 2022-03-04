# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.ans = []
        if not root:
            return []
        def DFS(node, depth):
            if depth-1==len(self.ans):
                self.ans.append(node.val)
            if node.right:
                DFS(node.right, depth+1)
            if node.left:
                DFS(node.left, depth+1)
        DFS(root, 1)
        return self.ans
