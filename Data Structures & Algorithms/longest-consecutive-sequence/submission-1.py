class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        lcs = {}
        longest = 0
        nums_set = set(nums)
        
        for num in nums_set:
            if num-1 not in nums_set:
                n = 1
                c = num
                while c+1 in nums_set:
                    n += 1
                    c += 1
                if n > longest:
                    longest = n
        
        return longest
