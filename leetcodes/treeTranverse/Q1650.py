# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None


class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        ns = set()
        while p:
            ns.add(p.val)
            p = p.parent
        while q:
            if q.val in ns:
                return q
            q = q.parent
        return None
