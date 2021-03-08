# 파이썬 for문 순회의 다양한 방법

## 가장 일반적인 for문

```python
arr = [1,2,3,4]

for x in arr:
    print(x)
```

```console
순서대로 1 2 3 4가 출력됩니다.
```

## range를 활용한 for문

```python
arr = [1,2,3,4]

for x in range(1,len(arr)):
    print(x)
```

```console
2,3,4가 출력됩니다.
세번째 인자에는 증가할 수가 들어갑니다. 예를들어 -1을 집어넣으면 -1씩 감소하는 for문을 만들 수 있습니다.
```

## enumerate를 활용한 for문

```python
arr = [1,2,3,4]

for i,v in enumerate(arr):
    print(i,v)
```

```console
이 함수는 인덱스와 값을 동시에 보여주기에 적합한 함수이다.
인덱스를 활용해 참조가 필요하다면 사용하면 좋은 for문이다.

위의 출력 결과는
0, 1
1, 2
2, 3
3, 4
이다
```

## zip을 활용한 for문

```python
arr1 = [1,2,3,4]
arr2 = [2,3,4,5]

for x,y in zip(arr1,arr2):
    print(x+y)
```

```console
이 메서드는 여러개 같이 for문을 돌고 싶을때 사용하면 유용한 메서드이다.
위와 같은 코드는 3,5,7,9를 순서대로 출력한다.
```
