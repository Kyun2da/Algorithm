def recursive(n,sum):
    if n==0 or n==1:
        return sum
    return recursive(n-1,sum*n)


num = int(input())
res = recursive(num,1)
print(res)