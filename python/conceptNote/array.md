# 배열



## 1차원 배열 선언 방법

```python
arr = [0] * 100
```



## 인풋  받아서 1차원 배열 선언과 입력 동시에 받기

```python
arr = list(map(int,input().split()))
```



## 2차원 배열 선언 방법

```python
arr = [[0] * 100 for _ in range(100)] # 이렇게하면 100 * 100 의 2차원 배열이 생성된다.
```



## 인풋  받아서 1차원 배열 선언과 입력 동시에 받기

```python
n = int(input())

'''
만약 n = 3 일때
1 2 3
3 4 5
4 5 6
을 아래 한줄로 입력받을 수 있음
'''

arr = [list(map(int, input().split())) for _ in range(n)]
```

