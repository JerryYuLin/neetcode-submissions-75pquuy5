class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        def takeSec(e):
            return e[1]

        remains = [(float(target - p)/speed[i], p) for i, p in enumerate(position)]
        remains.sort(key=takeSec, reverse=True)

        waiting_stack = [remains[0]]
        fleet = 1

        for r in remains:
            if waiting_stack and waiting_stack[-1][0] < r[0]:
                waiting_stack = [r]
                fleet += 1

        return fleet