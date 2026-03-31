class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        partner_map = {}

        for i, num in enumerate(nums):
            partner = target - num

            if num in partner_map:
                return sorted([i, partner_map[num]])
            else:
                partner_map[partner] = i
