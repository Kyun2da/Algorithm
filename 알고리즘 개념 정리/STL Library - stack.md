## STL Library - stack

스택은 자료구조중 하나로  <span style="color:red"> *LIFO(Last In First Out)*</span>구조를 가지고 있다.

스택 선언 방법

```c++
#include <iostream>
#include <stack> //스택 라이브러리
using namespace std;

int main()
{
    stack <int> s; // 스택을 int형 변수로 선언
}
```



### 스택 제공 함수

- `push`  :  스택에 새로운 오브젝트를 삽입한다. ex) s.push(1);
- `pop`  :   스택에 가장 윗부분에 있는 오브젝트를 버린다.  ex) s.pop();
- `top` :  스택에서 가장 윗부분에 있는 오브젝트를 반환한다. pop과는 달리 오브젝트가 남아있다.  ex) s.top();
- `size` : 현재 스택의 사이즈를 반환한다. ex) s.size();
- `empty` : 현재 스택이 비어있는지 여부를 반환 (true-비어있음) ex)s.empty();
- `swap` : 두 스택의 내용을 바꿈 ex)s.swap(another_stack);
- `emplace` :  기본 자료형이 아닌 특정 클래스의 Stack이라면 해당 args를 그 클래스의 생성자로 넘겨 해당 클래스의 객체를 생성해서 Stack에 Push한다.



### 스택 사용 예시 코드

```c++
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack <int> s;
	stack <int> s2;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "size:" << s.size() << "\n"; //스택의 사이즈 변환

	cout << s.top() << "\n"; //스택의 맨위 반환
	s.pop(); //스택의 맨위 삭제 

	cout << s.top() << "\n"; //스택의 맨위 반환
	s.pop(); //스택의 맨위 삭제 

	cout << s.top() << "\n"; //스택의 맨위 반환
	s.pop(); //스택의 맨위 삭제 

	cout << "empty? " << s.empty() << "\n";  // 스택이 비었는지 bool 값 반환

	s.push(1);
	s.push(2);
	s.push(3);
	cout << "s2's size:" << s2.size() << "\n"; //스택2의 사이즈 변환
	s2.swap(s);
	cout << "s2's size:" << s2.size() << "\n"; //스택2의 사이즈 변환
	return 0;
}
```

### 실행 결과

![실행결과]()