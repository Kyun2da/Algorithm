import sys

input = sys.stdin.readline
n, l = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]

ans = 0


# 가로, 세로 한줄씩 총 2N개를 검사
# 만약 그 줄이 길이될수있다면 답에 추가
# 길이 될 수 없는 경우 : 높이차이가 1보다 클때, 높이차이가 1인데 경사로를 못놓을때
def check(tmp):
    i = 0
    # 경사로 설치여부의 배열
    vis = [False] * n
    while i < n - 1:
        # 높이차이가 1보다 크면 false를 리턴
        if abs(tmp[i] - tmp[i + 1]) > 1:
            return False

        # 오르막길이면 거꾸로 돌아가면서 경사로를 배치할 수 있는지 확인
        if tmp[i] - tmp[i + 1] == -1:
            for k in range(i, i - l, -1):
                if k < 0 or vis[k] or tmp[k] - tmp[i + 1] != -1:
                    return False
                vis[k] = True
        # 내리막길에 경사로 배치할 수 있는지 확인
        elif tmp[i] - tmp[i + 1] == 1:
            for k in range(1, l + 1):
                if i + k >= n or vis[i + k] or tmp[i] - tmp[i + k] != 1:
                    return False
                vis[i + k] = True
            i += l - 1
        i += 1
    return True


# 가로 검사
for i in range(n):
    if check(arr[i]):
        # print("가로")
        # print(arr[i])
        ans += 1

# 세로검사
for i in range(n):
    tmpArr = []
    for j in range(n):
        tmpArr.append(arr[j][i])
    if check(tmpArr):
        # print("세로")
        # print(tmpArr)
        ans += 1

print(ans)
