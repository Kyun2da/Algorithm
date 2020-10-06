import copy


def solution(numbers, hand):
    arr = [[1, 2, 3], [4, 5, 6], [7, 8, 9], ['*', 0, '#']]
    rp = [3, 2]
    lp = [3, 0]
    answer = ''
    for number in numbers:
        if number == 1 or number == 4 or number == 7:
            lp = [number // 3, 0]
            answer += 'L'
        elif number == 3 or number == 6 or number == 9:
            rp = [number // 3 - 1, 2]
            answer += 'R'
        else:
            np = []
            for i in range(len(arr)):
                if arr[i][1] == number:
                    np = [i, 1]
            rdiff = abs(np[0] - rp[0]) + abs(np[1] - rp[1])
            ldiff = abs(np[0] - lp[0]) + abs(np[1] - lp[1])
            if rdiff < ldiff:
                rp = copy.deepcopy(np)
                answer += 'R'
            elif rdiff > ldiff:
                lp = copy.deepcopy(np)
                answer += 'L'
            else:
                if hand == "left":
                    lp = copy.deepcopy(np)
                    answer += 'L'
                else:
                    rp = copy.deepcopy(np)
                    answer += 'R'

    return answer


print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))
