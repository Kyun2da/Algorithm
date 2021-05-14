n = input()
m = input()

length = len(m)
stack = []

for s in n:
    stack.append(s)
    if stack[-1] == m[-1] and ''.join(stack[-length:]) == m:
        del stack[-length:]

answer = ''.join(stack)

print('FRULA' if answer == "" else answer)
