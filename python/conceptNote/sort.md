# 정렬

[정렬 공식문서](https://docs.python.org/ko/3/howto/sorting.html)

### sort 메소드

가장 간단한 정렬 방법으로 리스트 자료형에만 사용이 가능하다.

```python
>>> a = [5, 2, 3, 1, 4]
>>> a.sort()
>>> a
[1, 2, 3, 4, 5]
```



### sorted 메소드

모든 이터러블을 받아들이는 메소드이다. 또한 원본이 보존된다는 장점이 있다.

```python
>>> sorted({1: 'D', 2: 'B', 3: 'B', 4: 'E', 5: 'A'})
[1, 2, 3, 4, 5]
```



### 키 함수

특정한 조건을 기준으로 정렬할 때 사용한다.

```python
>>> student_tuples = [
    ('john', 'A', 15),
    ('jane', 'B', 12),
    ('dave', 'B', 10),
]
>>> sorted(student_tuples, key=lambda student: student[2])   # sort by age
[('dave', 'B', 10), ('jane', 'B', 12), ('john', 'A', 15)]
```



### operator 모듈 함수

```python
>>> from operator import itemgetter, attrgetter
```

operator 모듈에는 itemgetter()와 attrgetter() 등이 있는데 이를 이용해 정렬을 좀더 편하게 할 수 있다.

위의 student_tuples를 간단하게 아래와 같이 정렬할 수 있다.

```python
>>> sorted(student_tuples, key=itemgetter(2))
[('dave', 'B', 10), ('jane', 'B', 12), ('john', 'A', 15)]
```

```python
>>> sorted(student_objects, key=attrgetter('age'))
[('dave', 'B', 10), ('jane', 'B', 12), ('john', 'A', 15)]
```



또한 다중 정렬도 가능하다.

```python
>>> sorted(student_tuples, key=itemgetter(1,2))
[('john', 'A', 15), ('dave', 'B', 10), ('jane', 'B', 12)]
```

```python
>>> sorted(student_objects, key=attrgetter('grade', 'age'))
[('john', 'A', 15), ('dave', 'B', 10), ('jane', 'B', 12)]
```



### 오름차순과 내림차순

sort와 sorted 함수는 모두 **reverse** 라는 매개 변수를 받아 들인다.

reverse=True 를 쓰면 내림차순으로 정렬되게 된다.

```python
>>> sorted(student_objects, key=attrgetter('age'), reverse=True)
[('john', 'A', 15), ('jane', 'B', 12), ('dave', 'B', 10)]
```







