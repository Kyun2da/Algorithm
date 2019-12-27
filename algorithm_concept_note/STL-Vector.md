# STL Library - Vector

벡터는 자동으로 메모리가 할당되는 배열이라고 생각하면 된다.

### 벡터 선언 방법

```c++
#include <iostream>
#include <vector> //벡터 라이브러리

int main()
{
    vector <int> v; //벡터 선언 방법
    vector <int>::iterator vi; //벡터 이터레이터 선언 방법
   
    return 0;
}
```

### 벡터의 생성자와 연산자

* `vector <int> v` :  비어있는 vector v를 생성한다.

  

* `vector <int> v(5)` : 0으로 초기화된 5개의 원소를 가지는 vector v를 생성한다.

  

* `vector <int> v(5,2)` : 2로 초기화된 5개의 원소를 가지는 vector v를 생성한다.

  

* `vector <int> v2(v1)` : v2는 v1 vector를 복사해서 생성된다.

  

### 벡터 제공 함수

*  `v.assign(5,2)` : 2의 값으로 5개의 원소 할당한다.



* `v.at(idx)` : idx번째 원소를 참조한다. v[idx]보다 속도는 느리지만,  범위를 점검하므로 안전하다.



* `v[idx]` : idx번째 원소를 참조한다. 범위를 점검하지 않으므로 속도가 v.at(idx)보다 빠르다.



* `v.front()` : 첫번째 원소를 참조한다.



* `v.back()` : 마지막 원소를 참조한다.



* `v.clear()` : 모든 원소를 제거한다, 원소만 제거하고 메모리는 남아있다, size만 줄어들고 capacity는 그대로 남아있다.



* `v.push_back(2)` : 마지막 원소뒤에 2를 삽입한다.



* `v.pop_back()` : 마지막 원소를 제거한다.



* `v.begin()` : 첫 번째 원소를 가리킨다 (iterator와 사용해야함)



* `v.end()` : 마지막 다음 원소를 가리킨다 (iterator와 사용해야함)



* `v.size()` : 원소의 갯수를 리턴한다.



* `v2.swap(v1)` : v1과 v2의 원소를 바꿔준다.



* `v.insert(v.begin(),3)` : v.begin()위치에 3을 추가한다 원래 있던 원소는 뒤로 밀린다.



* `v.insert(v.begin(),3,4)` : v.begin()위치에 3개의 4를 삽입한다. 원래 있던 원소는 뒤로 밀린다.



* `v.erase(iter)` : iter가 가리키는 원소를 제거한다.



* `v.empty()` : vector 가 비어있으면 true 를 리턴한다.



###  벡터 사용 예시 코드

```c++
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <string> v;
	vector <string>::iterator vi;

	v.assign(10, "ABC"); //10개의 벡터원소를 ABC로 채운다
	for (vi = v.begin(); vi != v.end(); vi++) //v.begin은 벡터의 처음을 가리키며 iterator 와 사용한다
	{                                         //v.end는 벡터의 마지막의 다음을 가리키며 iterator와 사용한다.
		cout << *vi << " ";
	}
	cout << endl;
	v.clear(); //벡터의 모든 원소를 삭제
	

	v.push_back("A"); //벡터의 다음에 A를 넣는다.
	v.push_back("B"); //벡터의 다음에 B를 넣는다.

	cout <<"v.at[0]의 값은 : "<< v.at(0) << endl; //벡터의 0번째 인덱스 원소 즉 A를 반환한다
	cout << endl;
	
	vector <int> v2;
	vector <int>::iterator vi2;

	for (int i = 0; i < 10; i++) //v2에 0부터 9까지 넣는다.
	{
		v2.push_back(i);
	}

	cout <<"v2[0]의 값은 : "  << v2[0] << endl;
	cout << "v2.front()의 값은 : " << v2.front() << endl;
	cout << "v2.back()의 값은 : " << v2.back() << endl;
	
	v2.pop_back(); //v2의 마지막 값을 지운다
	cout << "v2.back()의 값은 : " << v2.back() << endl;

	for (vi2 = v2.begin(); vi2 != v2.end(); vi2++)
	{
		cout << *vi2 << " ";
	}
	
	cout << endl << "v2의 사이즈는 ? : " << v2.size() << endl;
	
	
	v2.insert(v2.begin() + 3, 10); //vi2 이터레이터 위치에 10을 넣는다
	v2.insert(v2.begin()+3, 5, 300); //300을 5개 삽입
	for (vi2 = v2.begin(); vi2 != v2.end(); vi2++)
	{
		cout << *vi2 << " ";
	}
	return 0;
}
```



### 실행 결과

![실행결과](./algorithm_concept_note/img/vector_ex.png)  
