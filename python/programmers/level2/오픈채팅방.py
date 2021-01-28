def solution(records):
    answer = []
    dic = {}
    # 최종 닉네임을 결정
    for record in records:
        com = record.split(" ")
        if com[0] == 'Enter':
            dic[com[1]] = com[2]
        elif com[0] == 'Change':
            dic[com[1]] = com[2]

    # 답에 추가
    for record in records:
        com = record.split(" ")
        if com[0] == 'Enter':
            answer.append(dic[com[1]] + "님이 들어왔습니다.")
        elif com[0] == 'Leave':
            answer.append(dic[com[1]] + "님이 나갔습니다.")

    return answer


print(solution(
    ["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"]))
