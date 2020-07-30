arr = list(map(int,input().split()))

list1 = [1,2,3,4,5,6,7,8]
list2 = [8,7,6,5,4,3,2,1]

if list1 == arr:
    print('ascending')
elif list2 == arr:
    print('descending')
else:
    print('mixed')
