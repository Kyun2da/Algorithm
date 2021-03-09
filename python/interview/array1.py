# 중복이 없는가 : 문자열이 주어졌을 때, 이 문자열에 같은 문자가 중복되어 등장하는지 확인하는 알고리즘을 작성하라.
# 자료구조를 추가로 사용하지 않고 풀 수 있는 알고리즘 또한 고민하라

# 1. 먼저 해당 문자열이 아스키코드 문자열인지 유니코드 문자열인지 확인한다.
# 2. 보통 아스키코드라고 해보자

# 시간복잡도 : O(n), 공간복잡도 : O(1)
def isUniqueChars(str):
    if len(str) > 128: return False
    checkArr = [False] * 128
    for s in str:
        idx = ord(s)
        if checkArr[idx]: return False
        checkArr[idx] = True
    return True

# 비트마스크를 써서 공간을 1/8로 줄이는 방법 여기서 알파벳은 a ~ z로 가정
def isUniqueChars2(str):
    check = 0
    for s in str:
        val = ord(s) - ord('a')
        if check & (1 << val) > 0:
            return False
        check |= 1 << val
    return True

print(isUniqueChars2("abcdeff"))

'''
만약 자료구조를 추가적으로 쓰지 못한다면?
1. 문자열 내의 각 문자를 다른 모든 문자와 비교한다. 이렇게하면 O(n^2)이 걸리고 공간복잡도는 O(1)이다.
2. 입력 문자열을 수정해도 된다면, O(nlogn) 시간에 문자열을 정렬한뒤 문자열을 처음부터 훑어 나가면서 인접한 문자가 동일한지 검사해 볼수 있다.
   이때 많은 정렬알고리즘들이 추가적인 공간을 쓴다는 것을 주의하자.
'''