'''
문자열 두 개가 주어졌을 때 이 둘이 서로 순열 관계에 있는지 확인하는 메서드를 작성하라
'''


# 풀이 1 단순히 두 스트링을 정렬한값이 같은지만을 확인하면 됨
def isPermutation(s1, s2):
    if sorted(s1) == sorted(s2):
        return True
    return False


# 풀이 2 문자열에 포함된 문자의 출현 횟수가 같은지 검사하기
def isPermutation2(s1, s2):
    if len(s1) != len(s2):
        return False

    letters = [0] * 128

    for s in s1:
        letters[ord(s)] += 1
    for s in s2:
        letters[ord(s)] -= 1
        if letters[ord(s)] < 0:
            return False
    return True


print(isPermutation2("ab", "ba"))
