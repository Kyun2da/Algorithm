from collections import deque

n = int(input())

clipboard = 0
q = deque([[1, 0]])
vis = [[0] * 1001 for i in range(1001)]
vis[1][0] = 1

if n == 1:
    print(0)
    exit()

count = -1
while q:
    count += 1
    # bfs 수행
    for _ in range(len(q)):
        emoticon, clipboard = q.popleft()
        # print(emoticon, clipboard)
        if emoticon == n:
            print(count)
            exit()
        # 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
        # 클립보드에 이모티콘을 복사하면 이전에 클립보드에 있던 내용은 덮어쓰기가 된다.
        if not vis[emoticon][emoticon]:
            q.append([emoticon, emoticon])
            vis[emoticon][emoticon] = 1
        # 클립보드가 비어있는 상태에는 붙여넣기를 할 수 없으며, 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
        if 1 <= emoticon + clipboard <= n and not vis[emoticon + clipboard][clipboard]:
            q.append([emoticon + clipboard, clipboard])
            vis[emoticon + clipboard][clipboard] = 1
        # 화면에 있는 이모티콘 중 하나를 삭제한다.
        if emoticon - 1 >= 0 and not vis[emoticon - 1][clipboard]:
            q.append([emoticon - 1, clipboard])
            vis[emoticon - 1][clipboard] = 1
