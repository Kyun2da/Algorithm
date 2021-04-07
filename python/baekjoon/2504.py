s = input()

stack = []

answer = 0
for x in s:
    if x == '(':
        stack.append('(')
    elif x == ')':
        tmp = 0
        while len(stack) != 0:
            top = stack.pop()
            if top == '[':
                print(0)
                exit()
            elif top == '(':
                if tmp == 0:
                    stack.append(2)
                else:
                    stack.append(tmp * 2)
                break
            else:
                tmp += top
    elif x == '[':
        stack.append('[')
    else:
        tmp = 0
        while len(stack) != 0:
            top = stack.pop()
            if top == '(':
                print(0)
                exit()
            elif top == '[':
                if tmp == 0:
                    stack.append(3)
                else:
                    stack.append(tmp * 3)
                break
            else:
                tmp += top
    # print(stack)

for i in stack:
    if i == '(' or i == ')':
        print(0)
        exit()
    else:
        answer += i

print(answer)
