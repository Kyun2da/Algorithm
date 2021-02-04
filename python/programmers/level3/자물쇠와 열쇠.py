def attach(x, y, M, key, board):
    for i in range(M):
        for j in range(M):
            board[x + i][y + j] += key[i][j]


def detach(x, y, M, key, board):
    for i in range(M):
        for j in range(M):
            board[x + i][y + j] -= key[i][j]


def rotate(arr, d):
    l = len(arr)
    ret = [[0] * l for _ in range(l)]

    if d % 4 == 1:
        for i in range(l):
            for j in range(l):
                ret[j][l - 1 - i] = arr[i][j]
    elif d % 4 == 2:
        for i in range(l):
            for j in range(l):
                ret[l - 1 - i][l - 1 - j] = arr[i][j]
    elif d % 4 == 3:
        for i in range(l):
            for j in range(l):
                ret[l - 1 - j][i] = arr[i][j]
    else:
        for i in range(l):
            for j in range(l):
                ret[i][j] = arr[i][j]

    return ret


def isAnswer(newLock, length):
    for i in range(length, length * 2):
        for j in range(length, length * 2):
            if newLock[i][j] != 1:
                return False
    return True


def solution(key, lock):
    lockLen = len(lock)
    keyLen = len(key)
    newLocklength = lockLen * 3
    arr = [[0] * newLocklength for _ in range(newLocklength)]
    for i in range(lockLen, lockLen * 2):
        for j in range(lockLen, lockLen * 2):
            arr[i][j] = lock[i - lockLen][j - lockLen]

    for i in range(4):
        rotateKey = rotate(key, i)
        for j in range(newLocklength - keyLen):
            for k in range(newLocklength - keyLen):
                attach(j, k, keyLen, rotateKey, arr)
                if isAnswer(arr, lockLen):
                    return True
                detach(j, k, keyLen, rotateKey, arr)
    return False


print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]))
