import bisect

def solution(info, query):
    answer = []
    cases = []
    # 16가지의 경우의수 나누기
    for i in range(2):
        for j in range(2):
            for k in range(2):
                for m in range(2):
                    cases.append([i, j, k, m])
    dic = {}
    for item in info:
        data = item.split(" ")
        score = int(data[-1])
        data = data[:4]
        # 16가지의 경우의수에 따라 dic에 추가
        for case in cases:
            newData = []
            for i in range(4):
                if case[i] == 0:
                    newData.append('-')
                else:
                    newData.append(data[i])
            # print(newData)
            s = ' '.join(map(str, newData))
            if s not in dic:
                dic[s] = [int(score)]
            else:
                dic[s].append(int(score))

    # 나중에 이진탐색을 위해 정렬
    for key in dic.keys():
        dic[key].sort()

    # print(dic)
    # 쿼리문에따라 사람수 계산
    for q in query:
        q = q.split()
        newQ = ""
        for i, v in enumerate(q):
            if i % 2 == 0:
                newQ += v + " "
        newQ = newQ[:-1]
        # print(newQ)
        score = int(q[-1])
        if newQ not in dic:
            answer.append(0)
        else:
            # print(q[-1])
            size = len(dic[newQ])
            cnt = size - bisect.bisect_left(dic[newQ], score, lo=0, hi=size)
            answer.append(cnt)

    return answer


print(solution(
    ["java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150",
     "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"],
    ["java and backend and junior and pizza 100", "python and frontend and senior and chicken 200",
     "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100",
     "- and - and - and - 150"]))
