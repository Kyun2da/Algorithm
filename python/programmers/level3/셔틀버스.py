# n 회 t 분 간격 최대 m 명
def solution(n, t, m, timetable):
    timetable = [int(time[:2]) * 60 + int(time[3:5]) for time in timetable]
    timetable.sort()
    lastTime = 60 * 9 + (n - 1) * t

    for i in range(n):
        if len(timetable) < m:
            return '%02d:%02d' % (lastTime // 60, lastTime % 60)
        if i == n - 1:
            if timetable[0] <= lastTime:
                lastTime = timetable[m - 1] - 1
            return '%02d:%02d' % (lastTime // 60, lastTime % 60)
        for j in range(m - 1, -1, -1):
            busArrive = 60 * 9 + i * t
            if timetable[j] <= busArrive:
                del timetable[j]


print(solution(1, 1, 5, ["08:00", "08:01", "08:02", "08:03"]))
