def solution(nums):
    s = set(nums)
    if len(nums)//2 <= len(s):
        return len(nums)//2
    else:
        return len(s)

print(solution([3,3,3,2,2,2]))