class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l = len(nums)
        left_product = [1] * l
        right_product = [1] * l

        for i in range(1, l):
            left_product[i] = left_product[i-1] * nums[i-1]
            right_product[l-i-1] = right_product[l-i] * nums[l-i]
        
        return [left_product[i] * right_product[i] for i in range(l)]