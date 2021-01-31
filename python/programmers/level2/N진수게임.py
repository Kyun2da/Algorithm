'''
n : 진법
t : 미리 구할 숫자의 개수
m : 게임에 참가하는 인원
p : 튜브의 순서
'''
DIGITS = list('0123456789ABCDEF')


# 진법 변환 함수
def numberToBase(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(DIGITS[n % b])
        n = int(n // b)
    return digits[::-1]


def solution(n, t, m, p):
    answer = ''
    words = ""
    num = 0
    # 단어의 길이가 사람 수 * 필요한 글자수일때까지 실행
    while len(words) < t * m:
        words += ''.join(map(str, numberToBase(num, n)))
        num += 1
    print(words)
    for i in range(t):
        answer += words[i * m + p - 1]
    return answer


print(solution(16, 16, 2, 1))
