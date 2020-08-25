# 주요 라이브러리

### itertools

itertools는 파이썬에서 반복되는 데이터를 처리하는 기능을 포함하고 있는 라이브러리이다.

코딩 테스트에서 유용하게 사용할 수 있는 클래스는 **permutations, combinations**이다.

permutations는 리스트와 같은 iterable 객체에서 r개의 데이터를 뽑아 일렬로 나열하는 모든 경우를 계산해준다.

```python
from itertools import permutations

data = ['A', 'B', 'C'] # 데이터 준비

result = list(permutations(data, 3)) # 모든 순열 구하기, 리스트 data에서 3개를 뽑아 나열하는 모든 경우의 수

print(result)
# [('A', 'B', 'C'), ('A', 'C', 'B'), ('B', 'A', 'C'), ('B', 'C', 'A'), ('C', 'A', 'B'), ('C', 'B', 'A')]
```



combination는 리스트와 같은 iterable 객체에서 r개의 데이터를 뽑아 순서를 고려하지 않고 나열하는 모든 경우(조합)를 계산한다.

```python
from itertools import combinations

data = ['A', 'B', 'C'] # 데이터 준비
result = list(combinations(data, 2)) # 2개를 뽑는 모든 조합 구하기

print(result)
# [('A', 'B'), ('A', 'C'), ('B', 'C')]
```



product는 permutations와 같이 리스트와 같은 iterable 객체에서 r개의 데이터를 뽑아 일렬로 나열하는 모든 경우(순열)를 계산한다. 

다만 원소를 중복하여 뽑는다.

```python
from itertools import product

data = ['A', 'B', 'C'] # 데이터 준비
result = list(product(data, repeat=2)) # 2개를 뽑는 모든 순열 구하기(중복 허용)

print(result)
# [('A', 'A'), ('A', 'B'), ('A', 'C'), ('B', 'A'), ('B', 'B'), ('B', 'C'), ('C', 'A'), ('C', 'B'), ('C', 'C')]
```



### heapq

파이썬에서는 힙기능을 위해 heapq 라이브러리를 제공한다. heapq는 다익스트라 최단 경로 알고리즘을 포함해 다양한 알고리즘에서 **우선순위큐**를 구현하고자 할 때 사용된다.

파이썬의 힙은 최소 힙으로 구현되어 있으므로 단순히 원소를 힙에 전부 넣었다가 빼는 것만으로도 시간 복잡도 **O(NlogN)**에 오름차순 정렬이 완료 된다.

```python
# 최소 힙 구현

import heapq

def heapsort(iterable):
    h = []
    result = []
    # 모든 원소를 차례대로 힙에 삽입
    for value in iterable:
        heapq.heappush(h, value)
    # 힙에 삽입된 모든 원소를 차례대로 꺼내어 담기
    for i in range(len(h)):
        result.append(heapq.heappop(h))
    return result

result = heapsort([1, 3, 5, 7, 9, 2, 4, 6, 8, 0])
print(result)
# [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```



```python
# 최대 힙 구현

import heapq

def heapsort(iterable):
    h = []
    result = []
    # 모든 원소를 차례대로 힙에 삽입
    for value in iterable:
        heapq.heappush(h, -value)
    # 힙에 삽입된 모든 원소를 차례대로 꺼내어 담기
    for i in range(len(h)):
        result.append(-heapq.heappop(h))
    return result

result = heapsort([1, 3, 5, 7, 9, 2, 4, 6, 8, 0])
print(result)
# [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
```



### bisect

파이썬에서는 이진 탐색을 쉽게 구현할 수 있도록 bisect 라이브러리를 제공한다. bisect 라이브러리는 '정렬된 배열'에서 특정한 원소를 찾아야 할 때 매우 효과적으로 사용된다. bisect 라이브러리에서는 **bisect_left()** 메서드와 **bisect_right()** 메서드가 가장 중요하게 사용되며, 이 두 메서드는 시간 복잡도 **O(logN)**에 동작한다.

- bisect_left(a, x): 정렬된 순서를 유지하면서 리스트 a에 데이터 x를 삽입할 가장 왼쪽 인덱스를 찾는 메서드
- bisect_right(a, x): 정렬된 순서를 유지하도록 리스트 a에 데이터 x를 삽입할 가장 오른쪽 인덱스를 찾는 메서드

예를 들어 정렬된 리스트 [1, 2, 4, 4, 8]이 있을 때, 새롭게 데이터 4를 삽입하려 한다고 가정하면,

bisect_left(a, 4)와 bisect_right(a, 4)는 각각 인덱스값으로 2와 4를 반환한다.

```python
from bisect import bisect_left, bisect_right

a = [1, 2, 4, 4, 8]
x = 4

print(bisect_left(a, x)) # 2
print(bisect_right(a, x)) # 4
```



원소의 값을 x 라고 할 때, left_value <= x <= right_value인 원소의 개수를 O(logN)으로 빠르게 계산할 수 있다.

```python
from bisect import bisect_left, bisect_right

# 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
def count_by_range(a, left_value, right_value):
    right_index = bisect_right(a, right_value)
    left_index = bisect_left(a, left_value)
    return right_index - left_index

# 리스트 선언
a = [1, 2, 3, 3, 3, 3, 4, 4, 8, 9]

# 값이 4인 데이터 개수 출력
print(count_by_range(a, 4, 4))  # 2

# 값이 [-1, 3] 범위에 있는 데이터 개수 출력
print(count_by_range(a, -1, 3)) # 6
```



### collections

파이썬의 collections 라이브러리는 유용한 자료구조를 제공하는 표준 라이브러리다.

collections 라이브러리의 기능 중에서 코딩 테스트에서 유용하게 사용되는 클래스는 deque와 Counter이다.

**deque** : 보통 파이썬에서는 큐를 구현할 때 deque를 사용한다.

|                            | 리스트 | deque               |
| -------------------------- | ------ | ------------------- |
| 가장 앞쪽에 원소 추가      | O(N)   | O(1)   appendleft() |
| 가장 뒤쪽에 원소 추가      | O(1)   | O(1)   append()     |
| 가장 앞쪽에 있는 원소 제거 | O(N)   | O(1)   popleft()    |
| 가장 뒤쪽에 있는 원소 제거 | O(1)   | O(1)   pop()        |



```python
from collections import deque

data = deque([2, 3, 4])
data.appendleft(1)
data.append(5)

print(data)
print(list(data)) # 리스트 자료형으로 변환

# deque([1, 2, 3, 4, 5])
# [1, 2, 3, 4, 5]
```



**collections**: 파이썬 collections 라이브러리의 Counter는 등장 횟수를 세는 기능을 제공한다. 구체적으로 리스트와 같은 iterable 객체가 주어졌을 때, 해당 객체 내부의 원소가 몇 번씩 등장했는지를 알려준다. 따라서 원소별 등장 횟수를 세는 기능이 필요할 때 짧은 소스코드로 이를 구현할 수 있다.

```python
from collections import Counter

counter = Counter(['red', 'blue', 'red', 'green', 'blue', 'blue'])

print(counter['blue'])
print(counter['green'])
print(dict(counter))

# 3
# 1
# {'red': 2, 'blue': 3, 'green': 1}
```



### math

math 라이브러리는 자주 사용되는 수학적인 기능을 포함하고 있는 라이브러리다.

팩토리얼, 제곱근, 최대공약수등을 계산해주는 기능을 포함하고 있다.

- **factorial**

```python
import math

print(math.factorial(5)) # 5팩토리얼을 출력
```

- **sqrt**

```python
import math

print(math.sqrt(7)) # 7의 제곱근을 출력
```

- **gcd**

```python
import math

print(math.gcd(21, 14)) # 21과 4의 최대공약수 출력
```

- **pi, e**

```python
import math

print(math.pi) # 파이를 출력
print(math.e) # 자연상수 e 출력
```

