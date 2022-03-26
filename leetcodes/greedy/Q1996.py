class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        pts = sorted(properties, key=lambda a: (a[0], -a[1]), reverse=True)
        print(pts)
        ans = 0
        maxDefence = pts[0][1]
        for index, value in enumerate(pts):
            if value[1] < maxDefence:
                ans += 1
            elif value[1] > maxDefence:
                maxDefence = value[1]
        return ans
