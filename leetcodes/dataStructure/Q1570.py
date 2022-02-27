class SparseVector:
    def __init__(self, nums: List[int]):
        self.sparseDict = dict()
        for index, num in enumerate(nums):
            if num!=0:
                self.sparseDict[index]=num
        

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        ans = 0
        for key in self.sparseDict:
            if vec.sparseDict.get(key):
                ans += self.sparseDict[key] * vec.sparseDict[key]
        return ans


# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)