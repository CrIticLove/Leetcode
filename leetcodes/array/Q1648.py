import heapq


class MaxHeap:
    def __init__(self, inventory: List[int]) -> None:
        self.h = []
        for i in inventory:
            heapq.heappush(self.h, -i)

    def pop(self) -> int:
        return -heapq.heappop(self.h)

    def push(self, num: int) -> None:
        heapq.heappush(self.h, -num)
        return


class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        maxHeap = MaxHeap(inventory)
        ans = 0
        for i in range(orders):
            num = maxHeap.pop()
            ans += num
            maxHeap.push(num-1)
        return ans
