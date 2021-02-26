def solution(gems):
    answer = [0, len(gems) - 1]
    lenGems = len(gems)
    n = len(set(gems))
    dic = {gems[0]: 1}

    start = 0
    end = 0
    while start < lenGems and end < lenGems:
        if len(dic) == n:
            if answer[1] - answer[0] > end - start:
                answer[0], answer[1] = start, end
            if dic[gems[start]] == 1:
                del dic[gems[start]]
            else:
                dic[gems[start]] -= 1
            start += 1
        else:
            end += 1
            if end == lenGems:
                break
            else:
                if dic.get(gems[end]) is None:
                    dic[gems[end]] = 1
                else:
                    dic[gems[end]] += 1
    answer[0] += 1
    answer[1] += 1
    return answer


print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))
