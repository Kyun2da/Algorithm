import sys

N = int(sys.stdin.readline())
arr = []
for _ in range(N):
    command = sys.stdin.readline().rstrip()
    if command.split()[0] == "push":
        arr.append(int(command.split()[1]))
    elif command == "pop":
        if len(arr) == 0:
            print(-1)
        else:
            print(arr[-1])
            arr.pop()
    elif command == "size":
        print(len(arr))
    elif command == "empty":
        if len(arr) == 0:
            print(1)
        else:
            print(0)
    else:
        if len(arr) == 0:
            print(-1)
        else:
            print(arr[-1])
