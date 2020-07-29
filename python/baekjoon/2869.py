import sys

A,B,V = map(int,sys.stdin.readline().split())

day = (V-B-1) // (A-B) +1
print(day)