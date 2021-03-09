'''
회문 순열 : 주어진 문자열이 회문의 순열인지 아닌지 확인하는 함수를 작성하라.
회문이란 앞으로 읽으나 뒤로 읽으나 같은 단어 혹은 구절을 의미하며, 순열이란 문자열을 재배치하는 것을 뜻한다.
회문이 꼭 사전에 등장하는 단어로 제한될 필요는 없다.
'''


# 풀이 1
# 순열이 회문이려면
# 1. 홀수인 문자가 하나여야한다는 점이다.

# 홀수인 문자가 한개 이상 존재하는 지 확인하는 함수
def checkMaxOneOdd(table):
    foundOdd = False
    for count in table:
        if count % 2 == 1:
            if foundOdd: return False
            foundOdd = True
    return True


def getCharNum(c):
    if ord('a') <= ord(c) <= ord('z'):
        return ord(c) - ord('a')
    return -1


def buildCharFrequencyTable(str):
    table = [0] * (ord('z') - ord('a') + 1)

    for s in str:
        x = getCharNum(s)
        if x != -1:
            table[x] += 1
    return table


def isPermutationOfPalindrome(phrase):
    table = buildCharFrequencyTable(phrase)
    return checkMaxOneOdd(table)

print(isPermutationOfPalindrome("tact coa"))

# 풀이 2.
# 어떤 알고리즘이든 문자열을 한번은 훑어야 하기 때문에 O(n)은 넘을 수 없다.
# 하지만 마지막에 홀수의 개수를 확인하기 보단 문자열을 훑으면서 홀수의 개수를 확인하는 것이 더 효율적일 수 있다.

# 풀이 3.
# 단지 등장횟수를 세지않고 홀수개의 문자열이 홀수번 등장하면되므로 비트마스크를 사용할 수 있다.