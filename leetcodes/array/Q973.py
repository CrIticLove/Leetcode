from queue import PriorityQueue


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        pq = PriorityQueue()

        def distance(point: List[int]) -> int:
            return point[0]*point[0]+point[1]*point[1]
        for point in points:
            if pq.qsize() < k:
                pq.put((-distance(point), point))
                continue
            (d, pt) = pq.get()
            if distance(point)+d < 0:
                pq.put((-distance(point), point))
            else:
                pq.put((d, pt))
        print(pq)
        ans = []
        for i in range(pq.qsize()):
            ans.append(pq.get()[1])
        return ans
