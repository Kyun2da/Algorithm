# STL Library - Deque

deque는 벡터의 단점을 보완한 것으로 배열 앞에 삽입/삭제가 필요할 때 쓰는 것이 좋다.

하지만 단점은 여전히 중간 값 삽입 삭제가 쉽지않으며 순차적으로 저장되므로 검색속도가 빠르지 않다는 점이 있다.



### deque 선언 방법

```c++
#include <iostream>
#include <deque> //데큐 라이브러리

using namespace std;

int main()
{
	deque <int> dq; //데큐 선언
	deque <int>::iterator iter; //데큐 이터레이터
}
```



### deque의 생성자와 연산자

* `deque dq` : 비어있는 deque dq를 생성한다.



* `deque dq(10)` :  default(0) 값으로 초기화 된 10개의 원소를 가진 dq를 생성한다.



* `deque dq(10,4)` : 4의 값으로 초기화된 10개의 원소를 가진 dq를 생성한다.



* `deque dq2(dq1)` : dq1을 복사한 dq2를 생성한다.



### deque 제공 함수

* `dq.assign(4,3)` : 3의 값으로 4개의 원소 할당한다.



* `dq.at(idx)` : idx번째 원소를 참조, dq[idx]보다 상대적으로 느림



* `dq[idx]` : idx번째 원소를 참조한다.



* `dq.front()` : 첫 번째 원소를 참조한다.



* `dq.back()` : 맨 마지막 원소를 참조한다.



* `dq.clear()` :  모든 원소를 제거한다.



* `dq.push_front(3)` :  dq의 첫 번째 원소 앞에 원소 3을 삽입한다.



* `dq.pop_front()` : dq의 첫번째 원소를 제거한다.



* `dq.push_back(5)` : dq의 마지막 원소뒤에 5를 삽입한다.



* `dq.pop_back()` : dq의 마지막 원소를 제거한다.



* `dq.begin()` : 첫 번째 원소를 가리킨다. (iterator 와 사용)



* `dq.end()` :  마지막의 다음을 가리킨다. (iterator와 사용)



* `dq.size()` : 원소의 개수를 리턴한다.



* `dq2.swap(dq1)` : dq1과 dq2를 바꿔준다.



* `dq.insert(dq.begin(),2,3)` : dq.begin() 위치에 2개의 3값을 삽입한다.



* `dq.erase(iter)` : iter가 가리키는 원소를 제거한다.



* `dq.empty()` : dq가 비었으면 true를 반환한다.

### deque 사용 예시 코드

```c++
#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque <int> dq;
	deque <int>::iterator iter;
	
	for (int i = 1; i <= 5; i++)
	{
		dq.push_back(i);
	}

	for (iter = dq.begin(); iter != dq.end(); iter++)
		cout << *iter<< " ";

	dq.push_front(10);
	dq.push_front(20);
	dq.push_back(100);
	dq.push_back(200);

	cout << endl;
	for (iter = dq.begin(); iter != dq.end(); iter++)
		cout << *iter << " ";

	dq.insert(dq.begin(), 3);
	dq.insert(dq.begin(), 3, 4);
	cout << endl;
	for (iter = dq.begin(); iter != dq.end(); iter++)
		cout << *iter << " ";
	return 0;
}
```



### 실행결과

![실행 결과](./algorithm_concept_note/img/deque_ex.png)  
