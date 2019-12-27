# STL Library - map

map은 연관 컨테이너중 하나이다.

균형 이진 트리로 구성되어 있다.

map은 key와 value로 이루어져있으며 이는 pair 객체 형태로 저장된다.

key는 고유한 값이므로 중복이 불가능하다

set과 마찬가지로 key값을 기준으로 자동정렬 된다.



### map 선언 방법

```c++
#inlcude <iostream>
#include <map> //map 라이브러리

using namespace std;

int main()
{
	map<int, int> m; //map 기본 선언방법
	map<int, int>::iterator iter; //map iterator


	return 0;
}
```



### map의 생성자와 연산자



* `map<int, int> m` : 기본 선언 방법



* `map<int> m(pred)` : pred를 통해 정렬기준을 세운다



* `map<int> m2(m1)` : m1을 복사한 m2를 생성한다



### map 제공 함수



* `m.begin()` :  맵의 맨처음을 가리킨다. iterator와 사용한다.



* `m.end()` :  맵의 맨끝의 다음을 가리킨다 . iterator와 사용한다.



* `m.clear()` :  맵을 초기화한다.



* `m.empty()` :  맵이 비워져있는지 확인하고 비워져있으면 true를 반환한다.



* `m.insert(pair[k,v])` :  map에 [k,v] 를 삽입한다.



* `m.erase(start,end)` :  start부터 end까지의 원소를 모두 삭제한다.



* `m.find(k)` : k값이 있는지 확인 iter로 사용



* `m.size()` :  맵의 원소의 개수를 반환한다.



### map 사용 예시 코드

```c++
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<int, string> m;
	map<int, string>::iterator iter;
	m.insert(pair<int, string>(40, "aaa"));
	m.insert(pair<int, string>(30, "ddd"));
	m.insert(pair<int, string>(70, "bbb"));
	m.insert(pair<int, string>(10, "ccc"));
	m.insert(pair<int, string>(20, "ggg"));
	m.insert(pair<int, string>(60, "fff"));

	for (iter = m.begin(); iter != m.end(); iter++)
		cout << "[" << iter->first << "," << iter->second << "] ";

	//오퍼레이터 []연산자 사용
	map<int, int> m2;
	map<int, int>::iterator iter2;

	m2[9] = 100;
	m2[1] = 10;
	m2[3] = 30;
	m2[7] = 20;
	m2[5] = 40;
	m2[13] = 90;
	m2[11] = 60;
	m2[15] = 100;
	m2[17] = 700;

	cout << endl;
	for(iter2=m2.begin(); iter2!=m2.end(); iter2++)
		cout << "[" << iter2->first << "," << iter2->second << "] ";
	return 0;
}
```



### 실행 결과

![실행 결과](./algorithm_concept_note/img/map_ex.png)  
