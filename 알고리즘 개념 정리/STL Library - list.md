# STL Library - list

list는 sequence container의 일종으로 순서를 유지하는 구조이다.

흔히 우리가 C언어 자료구조때 배운 이중 연결리스트라고 생각하면 된다.

포인터로 다음 값을 찾아주는 방식이므로 모든 삽입 삭제가 용이하지만 vector에서 가능했던 데이터의 위치로 값에 접근할 수는 없다.

### list 선언 방법

```c++
#include <iostream>
#include <list> //리스트 라이브러리

using namespace std;

int main()
{
    list<int> li;  // 리스트 선언
    list<int>::iterator iter;  // 리스트 이터레이터
}
```

### list의 생성자와 연산자

* `list li` : 비어있는 리스트 컨테이너 li를 생성한다.



* `list li(10)` : default(0)값으로 초기화 된 원소 10개를 가진 리스트를 생성한다



* `list li(3, 2)`  : 2값으로 초기화된 원소 3개를 가진 리스트를 생성한다.



* `list li2(li)` : list l1을 l2로 복사한다.



### list 제공 함수

* `li.assign(3,4)` : 4로 초기화된 3개의 원소를 할당한다.



* `li.front()` :  맨 앞의 원소를 반환한다.



* `li.back()` : 맨 뒤의 원소를 반환한다. 



* `li.begin()` :  맨 앞의 원소를 가리키는 iterator를 반환한다.



* `li.end()` :  맨 마지막의 다음 원소를 가리키는 iterator를 반환한다.



* `li.push_back(7)` :   뒤로 원소 7을 삽입한다.



* `li.push_front(7)` : 앞으로 원소 7을 삽입한다. 



* `li.pop_back()` :  맨 마지막 원소를 제거한다.



* `li.pop_front()` :  맨 앞 원소를 제거한다.



* `li.insert(iter,k)` : iterator가 가리키는 위치에 원소 k를 삽입한다. 



* `li.erase(iter)` :  iterator가 가리키는 원소를 삭제한다.



* `li.size()` :  원소의 개수를 반환한다.



* `li.remove(7)` :  7과 같은 원소를 모두 제거한다.



* `li.remove_if(Predicate)` : 단항 조건자 predicate에 해당하는 원소를 모두 제거한다. 



* `li.splice(iter,li2)` :  li에서 iter가 가리키는 곳에 li2의 모든 원소를 잘라 붙인다.



* `li.splice(iter,li2,iter2)` : li에서 iter가 가리키는 곳에 li2의 iter2가 가리키는 원소를 잘라 붙인다. 



* `li.splice(iter,li2,iter2_1,iter2_2)` :   li에서 iter가 가리키는 곳에 li2의 iter2_1에서 iter2_2까지가 가리키는 원소를 잘라 붙인다. 



* `li.unique()` : 인접한(양옆) 원소가 같으면 유일하게 만든다. (하나만 빼고 나머지를 다 삭제한다.) 



* `li.merge(li2)` :  li와 li2를 합병정렬하여 li에 오름차순으로 합친다. 두번째 파라미터로 이항조건자가 올 수 있다. 



### list 사용 예시 코드-1

```c++
#include <iostream>
#include <list>

using namespace std;

bool predicate(int num)
{
	return num >= 100 && num <= 200;
}
int main()
{
	list<int> li;
	list<int>::iterator iter;
	li.push_back(10);
	li.push_back(20);
	li.push_back(108);
	li.push_back(60);
	li.push_back(10);
	li.push_back(100);
	li.push_back(40);
	li.push_back(50);
	li.push_back(109);
	li.push_back(30);
	li.push_back(220);
	li.push_back(10);
	li.push_back(220);

	cout << "초기 list : ";
	for (iter = li.begin(); iter != li.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	li.remove_if(predicate);

	cout << "remove_if 후의 list : ";
	for (iter = li.begin(); iter != li.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	li.remove(10);

	cout << "remove(10) 후의 list : ";
	for (iter = li.begin(); iter != li.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	li.sort();

	cout << "sort 후의 list : ";
	for (iter = li.begin(); iter != li.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	
	li.unique();

	cout << "unique를 통해 220을 지운 후의 list : ";
	for (iter = li.begin(); iter != li.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
```



### 예시 코드1 실행 결과

![실행결과1]()  



### list 사용 예시 코드-2

```c++
#include <iostream>
#include <list>

using namespace std;
int main()
{
	list<string> li;
	list<string> li2;
	list<string>::iterator iter;
	li.push_back("a");
	li.push_back("b");
	li.push_back("c");
	li.push_back("d");
	li.push_back("e");

	li2.push_back("X");
	li2.push_back("Y");
	li2.push_back("Z");

	cout << "li : ";
	for (iter = li.begin(); iter != li.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "li2 : ";
	for (iter = li2.begin(); iter != li2.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	iter = li2.begin();
	iter++;
	li2.splice(iter, li);
	cout << "li2를 splice한 후 : ";
	for (iter = li2.begin(); iter != li2.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	list<int> li3;
	list<int> li4;
	list<int>::iterator iter2;
	li3.push_back(1);
	li3.push_back(2);
	li3.push_back(3);
	li3.push_back(4);
	li3.push_back(5);

	li4.push_back(6);
	li4.push_back(7);
	li4.push_back(8);

	cout << "li3 : ";
	for (iter2 = li3.begin(); iter2 != li3.end(); iter2++)
	{
		cout << *iter2 << " ";
	}
	cout << endl;

	cout << "li4 : ";
	for (iter2 = li4.begin(); iter2 != li4.end(); iter2++)
	{
		cout << *iter2 << " ";
	}
	cout << endl;

	li4.merge(li3);

	cout << "li4를 merge한 후의 li4 : ";
	for (iter2 = li4.begin(); iter2 != li4.end(); iter2++)
	{
		cout << *iter2 << " ";
	}
	cout << endl;
	return 0;
}
```



### 예시코드2 실행 결과

![실행결과2]()  





























