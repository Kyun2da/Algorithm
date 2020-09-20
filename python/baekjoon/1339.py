'''
def dfs(num):
    global ans
    if num == 10:
        # print(alpha)
        tmp = 0
        for x in arr:
            tmpStr = ""
            for k in x:
                tmpStr += str(alpha[ord(k) - 65])
            tmp += int(tmpStr)
        if tmp > ans:
            ans = tmp
        return
    for i in range(10):
        if vis[i]: continue
        vis[i] = True
        alpha[num] = i
        dfs(num + 1)
        vis[i] = False


n = int(input())

ans = 0
arr = []
vis = [False] * 10
alpha = [-1] * 10
for _ in range(n):
    arr.append(input())

dfs(0)
print(ans)
'''

n = int(input())
word = [list(map(lambda x: ord(x) - 65, input().rstrip())) for _ in range(n)]
alpha = [0] * 26

for i in range(n):
    j = 0
    for w in word[i][::-1]:
        alpha[w] += (10 ** j)
        j += 1

alpha.sort(reverse=True)
ans, t = 0, 9
for i in range(26):
    if alpha[i] == 0:
        break
    ans += (t * alpha[i])
    t -= 1

print(ans)
