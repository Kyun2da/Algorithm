T = int(input())

arr = [[1,0],[0,1]]

for i in range(2,41):
    arr.append([arr[i-1][0]+arr[i-2][0],arr[i-1][1]+arr[i-2][1]])

for i in range(T):
    N = int(input())
    print("%d %d"%(arr[N][0],arr[N][1]))