class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freq = {}
        for num in nums:
            if num not in freq:
                freq[num] = 1
            else:
                freq[num] += 1
        
        buckets = [[] for _ in range(len(nums))]

        for f in freq:
            buckets[freq[f]-1].append(f)
        ans = []
        while k!=0:
            n = buckets.pop()
            if len(n) != 0:
                k-= len(n)
                for i in n:
                    ans.append(i)

        return ans