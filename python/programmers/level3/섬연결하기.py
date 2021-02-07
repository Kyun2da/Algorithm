def solution(n, costs):
    answer = 0

    def find(target):
        if target == parent[target]:
            return target

        parent[target] = find(parent[target])
        return parent[target]

    def union(a, b):
        a = find(a)
        b = find(b)

        if a < b:
            parent[b] = a
        else:
            parent[a] = b

    parent = [i for i in range(n)]
    costs.sort(key=lambda x: x[2])

    edgeCount = 0
    for cost in costs:
        a, b, weight = cost
        if find(a) != find(b):
            union(a, b)
            answer += weight
            edgeCount += 1
        if edgeCount == n - 1:
            break

    return answer


print(solution(4, [[0, 1, 1], [0, 2, 2], [1, 2, 5], [1, 3, 1], [2, 3, 8]]))
