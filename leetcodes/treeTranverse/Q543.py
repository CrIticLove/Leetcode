# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        def DFS(node)->int:
            if not node:
                return 0
            leftlong = DFS(node.left)
            rightlong = DFS(node.right)
            if leftlong+rightlong>self.ans:
                self.ans = leftlong+rightlong
            return max(leftlong, rightlong)+1
        DFS(root)
        return self.ans
        