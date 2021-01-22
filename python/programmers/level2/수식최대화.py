from itertools import permutations
import copy


def solution(expression):
    answer = 0
    # 연산자 우선순위 순열 이용
    operRanks = ["+", "-", "*"]
    operRanks = list(permutations(operRanks, 3))

    # 숫자와 연산자 나누기
    operator = []
    numbers = []
    tmp = ""
    for s in expression:
        if s == "+" or s == "-" or s == "*":
            operator.append(s)
            if len(tmp) != 0:
                numbers.append(int(tmp))
                tmp = ""
        else:
            tmp += s
    numbers.append(int(tmp))

    # 연산자 우선순위대로 계산

    for operRank in operRanks:  # 순열
        newOper = copy.deepcopy(operator)
        newNumbers = copy.deepcopy(numbers)
        # print(operRank)
        for oper in operRank:  # 우선순위
            i = 0
            while len(newOper) > i:
                if oper == newOper[i]:
                    if oper == '+':
                        newNumbers[i] += newNumbers[i + 1]
                    elif oper == '-':
                        newNumbers[i] -= newNumbers[i + 1]
                    else:
                        newNumbers[i] *= newNumbers[i + 1]
                    newNumbers.pop(i + 1)
                    newOper.pop(i)
                    # print(newNumbers)
                    # print(newOper)
                    i -= 1
                    # print(i)
                i += 1
        #print(newNumbers)
        answer = max(abs(newNumbers[0]), answer)

    return answer


print(solution("50*6-3*2"))
