import sys


def isFactor(N, M):
    if M % N == 0: return True
    return False


def isMultiple(N, M):
    if N % M == 0: return True
    return False


while True:
    N, M = map(int, sys.stdin.readline().split())
    if N == 0 and M == 0:
        break
    if isFactor(N, M):
        print('factor')
    elif isMultiple(N, M):
        print('multiple')
    else:
        print('neither')
