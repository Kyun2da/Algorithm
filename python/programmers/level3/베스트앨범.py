def solution(genres, plays):
    answer = []

    genreDict = {}
    genreArr = []

    for i, (genre, play) in enumerate(zip(genres, plays)):
        if genre not in genreDict:
            genreDict[genre] = []
        genreDict[genre].append([i, play])

    for g in genreDict:
        genreDict[g].sort(key=lambda x: x[1], reverse=True)
        genreArr.append([g, sum(play for _, play in genreDict[g])])

    genreArr.sort(key=lambda x: x[1], reverse=True)

    # print(genreDict)
    # print(genreArr)
    for g, _ in genreArr:
        answer.extend([x[0] for x in genreDict[g][:2]])
    return answer


print(solution(['classic', 'pop', 'classic', 'classic', 'pop'], [500, 600, 150, 800, 2500]))
