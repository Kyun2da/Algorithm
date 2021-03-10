from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        s.reverse()
        return s


sol1 = Solution()

print(sol1.reverseString(["h","e","l","l","o"]))