def solution(routes):
    answer = 0
    routes.sort(key=lambda x: x[1])

    camera = -30001
    for x in routes:
        start = x[0]
        end = x[1]
        if start <= camera <= end:
            continue
        else:
            answer += 1
            camera = end
    return answer


print(solution([[-20, 15], [-14, -5], [-18, -13], [-5, -3]]))
