class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pos = -1
        for i in range(len(nums)-1, 0, -1):
            if nums[i-1] < nums[i]:
                pos = i-1
                break
        if pos == -1:
            nums.reverse()
            return

        # find the smallest big one
        smallestBig = pos+1
        for i in range(pos+2, len(nums)):
            if nums[i] > nums[pos] and nums[i] <= nums[smallestBig]:
                smallestBig = i

        # swap
        t = nums[pos]
        nums[pos] = nums[smallestBig]
        nums[smallestBig] = t

        # reverse
        left = pos+1
        right = len(nums)-1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
