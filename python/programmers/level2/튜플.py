def solution(s):
    a = s.lstrip("{").rstrip("}").split("},{")
    answer = []

    newS = []
    for i in a:
        newS.append(i.split(","))

    newS.sort(key=len)

    for i in newS:
        for j in range(len(i)):
            if int(i[j]) not in answer:
                answer.append(int(i[j]))

    return answer


print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
