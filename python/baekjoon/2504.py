import sys

s = input()

stack = []

answer = 0
for x in s:
    if x == ')':
        tmp = 0
        if len(stack) == 0:
            print(0)
            sys.exit(0)
        while len(stack) != 0:
            top = stack.pop()
            if top == '[':
                print(0)
                sys.exit(0)
            elif top == '(':
                if tmp == 0:
                    stack.append(2)
                else:
                    stack.append(tmp * 2)
                break
            else:
                tmp += top
    elif x == ']':
        tmp = 0
        if len(stack) == 0:
            print(0)
            sys.exit(0)
        while len(stack) != 0:
            top = stack.pop()
            if top == '(':
                print(0)
                sys.exit(0)
            elif top == '[':
                if tmp == 0:
                    stack.append(3)
                else:
                    stack.append(tmp * 3)
                break
            else:
                tmp += top
    elif x == '(' or x == '[':
        stack.append(x)
    else:
        print(0)
        sys.exit(0)
    # print(stack)

for i in stack:
    if i == '(' or i == '[':
        print(0)
        sys.exit(0)
    else:
        answer += i

print(answer)
