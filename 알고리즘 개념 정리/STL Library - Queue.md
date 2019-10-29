# STL Library - Queue

큐는 **FIFO(First In First Out)** 방식으로 동작되며 한쪽 끝에서 삽입되어 다른쪽 끝으로 나가는 구조를 가지고 있다.  

큐 컨테이너는 deque와 list 컨테이너에 붙어서 사용가능하나 **vector 컨테이너에는 불가능**하다.

### 큐 선언 방법

```C++
#include <iostream> 
#include <queue>  //큐 라이브러리 
using namespace std;
int main() 
{
	queue <int> q; //큐 선언
}
```



### 큐 제공 함수

- `push` :   큐에 오브젝트 추가 ex) q.push(1);

  

- `size` :  큐의 현재 사이즈 반환 ex) q.size();

  

- `front` :  큐의 맨 위 반환 ex)q.front();

  

- `back` : 큐의 맨 밑 반환 ex)q.back();



- `empty` : 큐가 비었는지 확인하고 비었으면 true반환 ex) q.empty();



- `pop` : 큐의 맨 위 삭제  ex) q.pop();



- `swap` : 서로다른 큐를 교환 ex) q.swap(q2);



### 큐 사용 예시 코드

```c++
#include <iostream> #include <queue>
using namespace std;
int main() 
{
	queue <int> q;  //큐 선언
    
    q.push(1); 
    q.push(2); 
    q.push(3);
    
	cout << "size : " << q.size() << "\n"; //큐의 사이즈 반환
	
	cout << q.front() <<" "<<q.back() << "\n";    // 큐의 맨 위와 맨 밑 반환 
	q.pop(); // 큐의 맨 위 삭제
	
	cout << q.front() << " " << q.back() << "\n";    // 큐의 맨 위와 맨 밑 반환 
	q.pop(); // 큐의 맨 위 삭제
	
	cout << q.front() << " " << q.back() << "\n";    // 큐의 맨 위와 맨 밑 반환 
	q.pop(); // 큐의 맨 위 삭제
    
	cout << "empty? " << q.empty() << endl;  // 큐가 비었는지 bool 값 반환 
    return 0;
}
```

### 실행 결과

![실행 결과]()