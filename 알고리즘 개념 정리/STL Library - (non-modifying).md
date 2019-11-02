# STL Library - (non-modifying)

이번에 설명할 함수는 알고리즘 헤더에 내장되어있는 non-modifying 함수들이다.

이번에는 주로 사용하는 find, find_if, count, count_if, equal, search 함수들에 대해서 다뤄보겠다.



## 1. find, find_if 함수

```
//find 함수
template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& val);
```

find 함수는 범위 안(first 부터 last 까지 )의 원소들 중  val과 일치하는 첫 번째 원소를 가리키는 반복자를 리턴한다. 만약 일치하는 원소를 찾지 못할 경우 last를 리턴한다.

이 함수는 원소를 비교할 때 operator ==을 사용한다.



find_if 함수는 value가 들어갈 곳에 조건을 넣는 것이다.





### find 함수 소스코드 예시

```c++
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsOdd(int i) {
	return ((i % 2) == 1);
}

int main() {
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	vector<int>::iterator it;

	// find 함수
	it = find(vec.begin(), vec.end(), 3);
	cout << "Find result : " << *it << endl;

	// find_if 함수
	it = find_if(vec.begin(), vec.end(), IsOdd);
	cout << "The first odd value is " << *it << '\n';
}
```



### find 함수 예시 실행결과

![실행결과]()  



## 2. count, count_if 함수

count 함수는 범위안 first부터 last 전까지의 원소들 중 value와 일치하는 원소들의 개수를 센다.

이 때 원소를 비교하기 위해 operator == 를 사용한다.

count_if 함수는 first부터 last 전 까지의 원소들 중 조건이 참을 리턴하는 원소들의 개수를 센다.



### count, count_if함수 소스코드 예시

```c++
#include <iostream>     // std::cout
#include <algorithm>    // std::count
#include <vector>       // std::vector
using namespace std;

bool IsOdd(int i) { return ((i % 2) == 1); }

int main() {
	// counting elements in array:
	int myints[] = { 10,20,30,30,20,10,10,20 };   // 8 elements
	int mycount = count(myints, myints + 8, 10);
	cout << "10 appears " << mycount << " times.\n";

	vector<int> myvector;
	for (int i = 1; i < 10; i++) myvector.push_back(i); // myvector: 1 2 3 4 5 6 7 8 9

	mycount = count_if(myvector.begin(), myvector.end(), IsOdd);
	cout << "myvector contains " << mycount << " odd values.\n";

	return 0;
}
```



### count, count_if함수 소스코드 실행 결과

![실행 결과]()



## 3. equal 함수

equal함수는 두개의 범위안에 있는 원소들이 같은지를 묻는 함수이다.

같으면 True, 다르면 False를 반환한다.



### equal함수 소스코드 예시

```c++
#include <iostream>     // std::cout
#include <algorithm>    // std::equal
#include <vector>       // std::vector
using namespace std;

bool mypredicate(int i, int j) {
	return (i == j);
}

int main() {
	int myints[] = { 20,40,60,80,100 };               //   myints: 20 40 60 80 100
	vector<int>myvector(myints, myints + 5);     // myvector: 20 40 60 80 100

	// using default comparison:
	if (equal(myvector.begin(), myvector.end(), myints))
		cout << "The contents of both sequences are equal.\n";
	else
		cout << "The contents of both sequences differ.\n";

	myvector[3] = 81;                                 // myvector: 20 40 60 81 100

	// using predicate comparison:
	if (equal(myvector.begin(), myvector.end(), myints, mypredicate))
		cout << "The contents of both sequences are equal.\n";
	else
		cout << "The contents of both sequences differ.\n";

	return 0;
}
```



### equal함수 소스코드 예시 실행결과

![실행결과]()  



## 4. search 함수

search 함수는 부분 원소열을 검색하는 방법이다.

원소열을 찾으면 처음으로 등장하는 위치의 시작점을 가리키는 이터레이터를 리턴한다.

원소열을 못찾으면 범위내의 마지막 원소를 가리키는 이터레이터를 리턴한다.

### search 함수 소스코드 예시

```c++
#include <iostream>     // std::cout
#include <algorithm>    // std::search
#include <vector>       // std::vector
using namespace std;

bool mypredicate(int i, int j) {
	return (i > j);
}

int main() {
	vector<int> v;

	// set some values:        v: 10 20 30 40 50 60 70 80 90
	for (int i = 1; i < 10; i++) v.push_back(i * 10);

	// using default comparison:
	int needle1[] = { 40,50,60,70 };
	vector<int>::iterator it;
	it = search(v.begin(), v.end(), needle1, needle1 + 4);

	if (it != v.end())
		cout << "needle1 found at position " << (it - v.begin()) << '\n';
	else
		cout << "needle1 not found\n";

	return 0;
}
```



### search 함수 소스코드 예시 실행결과

![실행 결과]()