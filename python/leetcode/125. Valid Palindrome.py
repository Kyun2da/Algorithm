class Solution:
    def isPalindrome(self, s: str) -> bool:
        new_s = ""
        for char in s:
            if char.isalnum():
                new_s += char.lower()
        if new_s == new_s[::-1]:
            return True
        return False


sol1 = Solution()

print(sol1.isPalindrome("A man, a plan, a canal: Panama"))
