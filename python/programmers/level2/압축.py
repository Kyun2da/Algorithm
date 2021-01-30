'''
1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
3. w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
4. 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
단계 2로 돌아간다.
'''


def solution(msg):
    answer = []
    arr = []
    # 1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    for i in range(26):
        arr.append(chr(65 + i))

    i = 0
    length = len(msg)
    if len(msg) == 1:
        return [arr.index(msg)+1]
    while msg:
        # 2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
        j = 1
        while i + j < length and msg[i:i + j] in arr:
            j += 1
        # 3. w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
        answer.append(arr.index(msg[i:i + j - 1]) + 1)
        # 4. 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
        arr.append(msg[i:i + j])
        msg = msg[i + j - 1:]
    return answer


# print(solution('KAKAO'))
# print(solution('TOBEORNOTTOBEORTOBEORNOT'))
# print(solution("ABABABABABABABAB"))
print(solution("A"))
