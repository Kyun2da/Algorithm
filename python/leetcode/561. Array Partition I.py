from typing import List


# 앞에서부터 오름차순이 solution이다
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        answer = 0
        for i, v in enumerate(nums):
            if i % 2 == 0:
                answer += v
        return answer


sol1 = Solution()
print(sol1.arrayPairSum([1, 4, 3, 2]))
