class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        ans = [0] * len(temperatures)
        waiting_stack = []

        for i, t in enumerate(temperatures):
            while waiting_stack and temperatures[waiting_stack[-1]] < t:
                w = waiting_stack.pop()
                ans[w] = i - w

            waiting_stack.append(i)
        
        return ans