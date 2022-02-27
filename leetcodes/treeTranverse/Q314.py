from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        queue = deque()
        if not root:
            return []
        queue.append((root, 0))
        answerDict = dict()
        while len(queue):
            (node, pos) = queue.popleft()
            if not answerDict.get(pos):
                answerDict[pos] = []
            answerDict[pos].append(node.val)
            if node.left:
                queue.append((node.left, pos-1))
            if node.right:
                queue.append((node.right, pos+1))
        ans = []
        for k in sorted(answerDict.keys()):
            ans.append(answerDict[k])
        return ans
            