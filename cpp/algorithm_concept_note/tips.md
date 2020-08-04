# 팁 정리

------

### 2의 제곱을 표현할 때

pow함수를 쓸 필요 없이 비트연산자 **1<<N** 을 쓰면 2의 N승을 의미한다.



------

### ios::sync_with_stdio(false)

보통 이것을 입출력 속도를 개선하기 위해 C++을 쓰곤하는데 이것을쓰면

절대로 C의 문법을 쓰면 안된다. 따라서 getchar()같은 문법을 쓸 수 없다.

이를 주의하자.



------

### C++로 출력할때 소수점 고정하기

C는 %.2lf 이런 식으로 출력할 수 있지만 C++는 어떻게 출력해야할지 몰라서 찾아보았다.

```c++
cout << fixed; //소수점을 고정시켜 표현하겠다.
cout.precision(2); // 소수점둘째자리까지 표현하겠다.
```

이 두 표현을 합치면 소수점 둘째자리까지 고정시켜 표현하겠다는 뜻이다.

그러므로 1이어도 1.00이 출력되고 2.435이면 2.44인 반올림해서 출력이 된다.



------

### 배열 쉽게 복사(Deep Copy)하기

http://www.devpia.com/MAEUL/Contents/Detail.aspx?BoardID=51&MAEULNo=20&no=8760&ref=8760
이 문서를 참조하면 for loop, memcpy, std::copy가 나오는데 이 for loop은 문서에 따르면 느리기 때문에 memcpy나 std::copy를 사용하면 된다

```c++
#include <string.h>

void *memcpy(void *dest, const void *src, size_t n);
```

```c++
#include <algorithm>
int arr[10];
int arr2[10;]
std::copy( arr, arr+10, arr2 ); // arr를 arr2로 복사하겠다
```



------

### 내림차순 정렬 쉽게하기

```c++
#include <iostream>
#include <algorithm>
#include <functional> //greater함수를 쓰기 위해 필요함

int main(){
int arr[10];
for(int i=0; i<10; i++)
	cin >> arr[i];
sort(arr,arr+10, greater<int>()); //이 greater함수를 사용하면 쉽게 내림차순 정렬을 할 수 있음
return 0;
}
```

