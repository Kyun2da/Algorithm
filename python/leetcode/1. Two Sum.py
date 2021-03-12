from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_map = {}
        for i, num in enumerate(nums):
            if target - num in nums_map:
                return [nums_map[target - num], i]
            nums_map = i


sol1 = Solution()

print(sol1.twoSum([2, 7, 11, 15], 9))
