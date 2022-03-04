class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda i: i[0])
        ans = [intervals[0]]
        for i in range(1, len(intervals)):
            st, ed = intervals[i][0], intervals[i][1]
            if st>=ans[-1][0] and st<=ans[-1][1]:
                ans[-1] = [ans[-1][0], max(ans[-1][1], ed)]
            else:
                ans.append(intervals[i])
        return ans
        