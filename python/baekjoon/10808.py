arr = [0] * 26

s = input()
for x in s:
    arr[ord(x) - 97] += 1

print(' '.join(map(str, arr)))
