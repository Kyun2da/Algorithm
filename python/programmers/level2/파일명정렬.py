def solution(files):
    answer = []
    arr = []
    for file in files:
        # 숫자의 시작인덱스와 끝 인덱스
        # 파싱해주기 위해 숫자의 처음인덱스와 끝인덱스를 찾는다.
        idx = 0
        nameLen = len(file)
        startIdx = None
        endIdx = None
        while idx < nameLen:
            if '0' <= file[idx] <= '9':
                endIdx = idx
                if startIdx is None:
                    startIdx = idx
            elif startIdx is not None:
                break
            if endIdx is not None and startIdx is not None and endIdx - startIdx == 4:
                break
            idx += 1

        head = file[:startIdx].lower()
        number = int(file[startIdx:endIdx + 1])
        tail = file[endIdx + 1:]
        # print("%s, %s, %s" % (head, number, tail))
        # 배열에 추가
        arr.append([file, head, number, tail])

    # 배열 정렬
    arr.sort(key=lambda x: (x[1], x[2]))

    # 정렬을 토대로 answer에 추가
    for item in arr:
        answer.append(item[0])
    return answer


print(solution(['img12.png', 'img10.png', 'img02.png', 'img1.png', 'IMG01.GIF', 'img2.JPG']))
