N = int(input())

if N == 1:
    print('*')

else:
    if N % 2 == 0:
        a = '* ' * (N // 2)
        b = ' *' * (N // 2)
    else:
        a = '* ' * (N // 2) + '*'
        b = ' *' * (N // 2)

    for _ in range(N):
        print(a)
        print(b)