# 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
# 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.

# 기둥 설치가 가능한 경우
# 1. 맨 밑에 있을 경우
# 2. 보의 한쪽 끝 부분 위에 있는 경우
# 3. 다른 기둥 위에 있는 경우

# 보 설치가 가능한 경우
# 1. 한쪽 끝 부분이 기둥 위에 있는 경우
# 2. 양쪽 끝 부분이 다른 보와 동시에 연결 된 경우


def impossibleBuild(answer):
    for x, y, a in answer:
        if a == 0:  # 기둥일 때 : 바닥에 없고, 아랫부분이 기둥이 아니고, 한쪽 끝 부분이 보가 아니면 불가능
            if y != 0 and (x, y - 1, 0) not in answer and (x - 1, y, 1) not in answer and (x, y, 1) not in answer:
                return True
        else:  # 보일 때 : 양쪽 끝이 기둥위에 있지 않고, 양쪽 끝부분이 다른보와 동시에 연결되지 않은 경우
            if (x, y - 1, 0) not in answer and (x + 1, y - 1, 0) not in answer and not (
                    (x - 1, y, 1) in answer and (x + 1, y, 1) in answer):
                return True


def solution(n, build_frame):
    answer = set()

    for x, y, a, b in build_frame:
        item = (x, y, a)
        if b == 1:  # 구조물 짓기
            answer.add(item)
            if impossibleBuild(answer):
                answer.remove(item)
        elif item in answer:  # 구조물 삭제하기
            answer.remove(item)
            if impossibleBuild(answer):
                answer.add(item)

    answer = map(list, answer)
    return sorted(answer, key=lambda t: (t[0], t[1], t[2]))


print(solution(5, [[1, 0, 0, 1], [1, 1, 1, 1], [2, 1, 0, 1], [2, 2, 1, 1], [5, 0, 0, 1], [5, 1, 0, 1], [4, 2, 1, 1],
                   [3, 2, 1, 1]]))
