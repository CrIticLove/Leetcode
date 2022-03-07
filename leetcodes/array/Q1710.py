class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes = sorted(boxTypes, key=lambda i: i[1], reverse=True)
        left = truckSize
        ans = 0
        while left > 0 and len(boxTypes) > 0:
            if left >= boxTypes[0][0]:
                left -= boxTypes[0][0]
                ans += boxTypes[0][0] * boxTypes[0][1]
                boxTypes = boxTypes[1:]
            else:
                ans += left * boxTypes[0][1]
                left -= boxTypes[0][0]
        return ans
