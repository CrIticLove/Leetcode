class Solution:
    def minSwaps(self, data: List[int]) -> int:
        oneCount = data.count(1)
        if oneCount in [0, 1]:
            return 0

        temp = data[:oneCount]
        maxct = temp.count(1)
        tempct = maxct
        for i in range(oneCount, len(data)):
            if data[i] == data[i-oneCount]:
                continue
            if data[i] == 1:
                tempct += 1
                if tempct > maxct:
                    maxct = tempct
                continue
            if data[i] == 0:
                tempct -= 1

        return oneCount-maxct
