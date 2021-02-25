def solution(n):
    def hanoi(n, From, Toward, Sub):
        if n == 1:
            answer.append([From, Toward])
            return
        hanoi(n - 1, From, Sub, Toward)  # 맨 마지막 원반을 제외하고 나머지를 보조 기둥으로 보낸다.
        answer.append([From, Toward])  # 시작 기둥에 혼자 있는 제일 큰 원반을 print
        hanoi(n - 1, Sub, Toward, From)  # 보조 기둥에 있는 제일 큰 원반을 제외하고 나머지를 다시 보조 기둥으로 보낸다.

    answer = []
    hanoi(n, 1, 3, 2)
    return answer


print(solution(2))
