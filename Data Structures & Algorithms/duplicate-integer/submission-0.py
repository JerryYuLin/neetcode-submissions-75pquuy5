class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        n = set()
        for num in nums:
            if num not in n:
                n.add(num)
            else:
                return True
        
        return False
