import sys

while True:
    try:
        a,b = map(int,sys.stdin.readline().split())
        print(a+b)
    except:
        break

'''
import sys
s = sys.stdin
for readline in s:
    a,b=map(int,readline.split())
    print(a+b)
'''