# 큐

선입선출(First In First Out) 구조



bfs에 주로 활용됨 



응용하여 원형 큐등의 문제도 나오기도 함

주로 파이썬의 deque 모듈을 활용함

큐 모듈은 멀티쓰레드 환경 지원때문에 느려서 모든 연산을 O(1)로 처리하는 deque 모듈을 종종 쓴다.



```python
from collections import deque

q = deque()

q.append(item)
q.popleft()
```

