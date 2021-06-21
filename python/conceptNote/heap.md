# 힙



우선순위 큐를 구현할 때 종종 쓰는 힙 자료구조



최대힙 최소힙 두가지 종류가 있다.



파이썬에서는 기본적으로 최소힙을 지원한다.



```python
import heapq

heap = []

# 최소 힙
heapq.heappush(heap, item)
heapq.heappop()

# 최대 힙은 임의로 원소에 - 값을 넣어서 생각
heapq.heappush(heap, -item)
heapq.heappop()
```

