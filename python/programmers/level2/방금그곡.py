def convertSharp(music):
    music = music.replace('C#', 'c')
    music = music.replace('D#', 'd')
    music = music.replace('F#', 'f')
    music = music.replace('G#', 'g')
    music = music.replace('A#', 'a')
    return music


def solution(m, musicinfos):
    answer = ""
    m = convertSharp(m)
    maxAns = 0
    for musicinfo in musicinfos:
        startTime, endTime, title, info = musicinfo.split(",")
        info = convertSharp(info)
        startHour, startMin = startTime.split(":")
        endHour, endMin = endTime.split(":")
        time = int(endHour) * 60 + int(endMin) - (int(startHour) * 60 + int(startMin))
        sheet = info * (time // len(info)) + info[:time % len(info)]
        if sheet.find(m) != -1 and maxAns < time:
            maxAns = time
            answer = title

    return "(None)" if answer == "" else answer


print(solution('ABC', ['12:00, 12:14, HELLO, C#DEFGAB', '13:00, 13:05, WORLD, ABCDEF']))
