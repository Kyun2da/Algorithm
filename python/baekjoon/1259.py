import sys

while True:
    str = sys.stdin.readline().rstrip()
    if str == '0':
        break
    if str == str[::-1]:
        print('yes')
    else:
        print('no')
