ans = 0


def solution(n):
    def dfs(arr):
        global ans
        length = len(arr)
        if length == n:
            ans += 1
            return
        candidate = list(range(n))
        for i in range(length):
            if arr[i] in candidate:  # 같은 열에 있는 지 확인
                candidate.remove(arr[i])  # 같은 열에 있다면 후보에서 제외
            distance = length - i
            if arr[i] + distance in candidate:  # 같은 대각성 상(+)에 있는 지 확인
                candidate.remove(arr[i] + distance)  # 같은 대각선 상에 있다면 후보에서 제외
            if arr[i] - distance in candidate:  # 같은 대각선 상(-)에 있는 지 확인
                candidate.remove(arr[i] - distance)  # 같은 대각선 상에 있다면 후보에서 제외
        if candidate:
            for i in candidate:
                arr.append(i)  # 후보의 요소를 정답 배열의 i+1로 추가
                dfs(arr)  # 재귀적으로 다음 행도 확인
                arr.pop()
        else:
            return

    for i in range(n):
        dfs([i])

    return ans


print(solution(4))
