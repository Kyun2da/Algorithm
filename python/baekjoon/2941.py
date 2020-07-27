croatia = ['c=','c-','dz=','d-','lj','nj','s=','z=']

str = input()

for i in range(len(croatia)):
    str = str.replace(croatia[i],'A')

print(len(str))