def solution(lines):
    sArr = []
    eArr = []
    for line in lines:
        s = line.split(" ")
        endSec = float(s[1][:2]) * 3600 + float(s[1][3:5]) * 60 + float(s[1][6:])
        startSec = endSec - float(s[2][:-1]) + 0.001
        sArr.append(startSec)
        eArr.append(endSec + 1)

    sArr.sort()

    curTraffic = 0
    maxTraffic = 0
    countEnd = 0
    countStart = 0
    lineLen = len(lines)
    while countEnd < lineLen and countStart < lineLen:
        if sArr[countStart] < eArr[countEnd]:
            curTraffic += 1
            maxTraffic = max(maxTraffic, curTraffic)
            countStart += 1
        else:
            curTraffic -= 1
            countEnd += 1

    return maxTraffic


print(solution([
    '2016-09-15 20:59:57.421 0.351s',
    '2016-09-15 20:59:58.233 1.181s',
    '2016-09-15 20:59:58.299 0.8s',
    '2016-09-15 20:59:58.688 1.041s',
    '2016-09-15 20:59:59.591 1.412s',
    '2016-09-15 21:00:00.464 1.466s',
    '2016-09-15 21:00:00.741 1.581s',
    '2016-09-15 21:00:00.748 2.31s',
    '2016-09-15 21:00:00.966 0.381s',
    '2016-09-15 21:00:02.066 2.62s'
]))
