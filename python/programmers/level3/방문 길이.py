pos = ['U', 'D', 'L', 'R']
dy = [1, -1, 0, 0]
dx = [0, 0, -1, 1]


def solution(dirs):
    start = [0, 0]
    s = set()
    for dir in dirs:
        idx = pos.index(dir)
        sy, sx = start
        end = [sy + dy[idx], sx + dx[idx]]
        if -5 <= end[0] <= 5 and -5 <= end[1] <= 5:
            s.add((sy, sx, end[0], end[1]))
            s.add((end[0], end[1], sy, sx))
            start = end

    return len(s) // 2


print(solution("LULLLLLLU"))
