arr=[]
for i in range(5):
    a= int(input())
    arr.append(a)

burger = min(arr[0],arr[1],arr[2])
coke = min(arr[3],arr[4])
print(burger+coke-50)