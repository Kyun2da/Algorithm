# 배열

알고리즘에서 가장 기초가되는 자료구조



처음 원소에 삽입 : O(N)

중간 원소에 삽입 : O(N)

끝 원소에 삽입 : O(1)

처음 원소 삭제 : O(N)

중간 원소 삭제 : O(N)

끝 원소 삭제 : O(1)





## 1차원 배열 선언 방법

```python
arr = [0] * 100
```



## 2차원 배열 선언 방법

```python
arr = [[0] * 100 for _ in range(100)] # 이렇게하면 100 * 100 의 2차원 배열이 생성된다.
```



## 다양한 인풋 받는 방법

```python
# 1차원 배열 인풋 받기
'''
n과 array원소가 주어질 때
4
1,2,3,4
'''

n = int(input())
arr = list(map(int,input().split()))

# 2차원 배열 인풋 받기
'''
n,m 과 array원소가 주어질 때
4 4
1 2 3 4 
5 6 7 8
9 10 11 12
13 14 15 16
'''

n,m = map(int,input().split())
arr = [list(map(int,input().split()) for _ in range(n))]
```

