# STL Library - set

set은 연관 컨테이너중 하나이다.

자료구조때 배웠던 균형 이진트리로 구현되어있다.

Key라고 불리는 원소들의 집합으로 이루어진 컨테이너이다.

Key값은 중복이 허용되지 않는다.

Key값은 자동으로 정렬된다.

정렬기준 default값은 오름차순이다.



### set 선언 방법

```c++
#include <iostream>
#include <set> //set 라이브러리

int main()
{
    set<int> s; //set 선언 방법
    
    return 0;
}
```



### set의 생성자와 연산자

* `set<int> s` : 기본 선언 방법



* `set<int> s(pred)` : pred를 통해 정렬기준을 세운다



* `set<int> s2(s1)` : s1을 s2에 복사한다



### set 제공 함수

* `s.begin()` :  첫번째 원소를 가리킨다. iterator와 쓰임



* `s.end()` :  맨 마지막원소의 다음을 가리킨다. iterator와 쓰임



* `s.clear()` :  모든 원소를 제거한다.



* `s.count(k)` :  원소 k의 갯수를 반환한다.



* `s.empty()` :  set s가 비어있는지 확인한다. 비어있으면 true를 반환한다.



* `s.insert(k)` : 원소 k를 삽입한다. 삽입한후 자동으로 정렬된다. 



* `s.erase(iter)` :  iter가 가리키는 원소를 제거한다



* `s.erase(start, end)` :  start~ end까지의 원소를 모두 제거한다.



* `s.swap(s2)` : s와 s2를 바꿔준다. 



* `s.size()` : 원소의 갯수를 반환한다. 



### set 사용 예시 코드

```C++
#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s;
	set<int>::iterator iter;

	s.insert(40);
	s.insert(10);
	s.insert(80);
	s.insert(30);
	s.insert(70);
	s.insert(60);
	s.insert(20);
	s.insert(50);

	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	//중복 값 넣으면? 중복 값은 들어가지 않는다
	s.insert(20);

	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << " ";
	cout << endl;


	iter = s.find(30);
	if (iter != s.end())
		cout << "존재" << endl;
	else
		cout << "존재x" << endl;

	iter = s.find(300);
	if (iter != s.end())
		cout << "존재" << endl;
	else
		cout << "존재x" << endl;
	return 0;
}
```



### 실행 결과

![실행결과]()  

