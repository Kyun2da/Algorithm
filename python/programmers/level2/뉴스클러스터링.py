import copy


def solution(str1, str2):
    str1 = str1.upper()
    str2 = str2.upper()

    arr1 = []
    arr2 = []

    for i in range(len(str1) - 1):
        if 'A' <= str1[i] <= 'Z' and 'A' <= str1[i + 1] <= 'Z':
            arr1.append(str1[i:i + 2])
    for i in range(len(str2) - 1):
        if 'A' <= str2[i] <= 'Z' and 'A' <= str2[i + 1] <= 'Z':
            arr2.append(str2[i:i + 2])

    lensum = len(arr1) + len(arr2)

    count = 0
    tmp = copy.deepcopy(arr1)
    for x in tmp:
        if x in arr2:
            arr1.remove(x)
            arr2.remove(x)
            count += 1

    if lensum - count == 0:
        answer = 65536
    else:
        answer = int(count / (lensum - count) * 65536)
    # print(arr1)
    # print(arr2)
    return answer


print(solution('E=M*C^2', 'e=m*c^2'))
