def solution(arr1, arr2):
    ans = [[0] * len(arr2[0]) for _ in range(len(arr1))]

    for i in range(len(arr1)):
        for j in range(len(arr2[0])):
            for k in range(len(arr1[0])):
                ans[i][j] += arr1[i][k]*arr2[k][j]

    return ans


print(solution([[1, 4], [3, 2], [4, 1]], [[3, 3], [3, 3]]))
