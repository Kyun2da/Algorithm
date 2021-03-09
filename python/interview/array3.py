'''
URLify : 문자열에 들어 있는 모든 공백을 '%20'으로 바꾸는 메서드를 작성하라.
최종적으로 모든 문자를 다 담을 수 있을 만큼 충분한 공간이 이미 확보되어 있으며 문자열의 최종 길이가 함께 주어진다고
가정해도 된다.
'''

# 파이썬에서는 메서드 사용하면 쉽지만 C나 자바라고 가정하고 생각한다.
def replaceSpaces(str):
    str = list(str)
    truelength = len(str)
    spaceCount = 0
    for i in str:
        if i == ' ':
            spaceCount += 1

    idx = truelength + spaceCount * 2
    str += [""] * spaceCount * 2
    if truelength < len(str): str[truelength] = '\0'
    for i in range(truelength - 1, -1, -1):
        if str[i] == ' ':
            str[idx - 1] = '0'
            str[idx - 2] = '2'
            str[idx - 3] = '%'
            idx -= 3
        else:
            str[idx - 1] = str[i]
            idx -= 1

    return ''.join(str)


print(replaceSpaces("Mr John Smith"))
