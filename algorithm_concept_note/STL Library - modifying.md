# STL Library - modifying

이번엔 modifying 함수중에서 copy, copy_if, swap, remove, remove_if, transform 함수에 대해 다뤄보겠다.



## 1. copy, copy_if 함수

copy 함수 설명은 다음과 같다.

```c++
template<class InputIterator, class OutputIterator>
  OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result)
{
  while (first!=last) {
    *result = *first;
    ++result; ++first;
  }
  return result;
}
```

copy_if 함수의 설명은 다음과 같다.

```c++
template <class InputIterator, class OutputIterator, class UnaryPredicate>
  OutputIterator copy_if (InputIterator first, InputIterator last,
                          OutputIterator result, UnaryPredicate pred)
{
  while (first!=last) {
    if (pred(*first)) {
      *result = *first;
      ++result;
    }
    ++first;
  }
  return result;
}
```



### copy, copy_if 함수 소스코드 예시

```c++
#include <iostream>     // std::cout
#include <algorithm>    // std::copy
#include <vector>       // std::vector
using namespace std;

int main() {
	int myints[] = { 10,20,30,40,50,60,70 };
	vector<int> myvector(7);
	vector<int> bar(myvector.size());

	copy(myints, myints + 7, myvector.begin());

	cout << "myvector contains:";
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	std::cout << '\n';


	auto it = std::copy_if(myints, myints + 7, bar.begin(), [](int i) {return i < 40; });
	bar.resize(distance(bar.begin(), it));
	cout << "bar contains:";
	for (vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
		cout << ' ' << *it;
	std::cout << '\n';


	return 0;
}
```

### copy, copy_if 함수 소스코드 예시 실행 결과

![실행 결과](https://github.com/Kyun2da/Algorithm/blob/master/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%20%EA%B0%9C%EB%85%90%20%EC%A0%95%EB%A6%AC/modifying_ex5.png)



## 2.  swap 함수 

swap함수의 정의는 다음과 같다.

```c++
template <class T> void swap (T& a, T& b)
{
  T c(std::move(a)); a=std::move(b); b=std::move(c);
}
template <class T, size_t N> void swap (T (&a)[N], T (&b)[N])
{
  for (size_t i = 0; i<N; ++i) swap (a[i],b[i]);
}
```



### swap 함수 소스코드 예시

```c++
#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include <vector>       // std::vector
using namespace std;

int main() {

	int x = 10, y = 20;                              // x:10 y:20
	swap(x, y);                              // x:20 y:10

	vector<int> foo(4, x), bar(6, y);       // foo:4x20 bar:6x10
	swap(foo, bar);                          // foo:6x10 bar:4x20

	cout << "foo contains:";
	for (vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	cout << "bar contains:";
	for (vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	return 0;
}
```





### swap함수 소스코드 예시 실행 결과

![실행 결과](https://github.com/Kyun2da/Algorithm/blob/master/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%20%EA%B0%9C%EB%85%90%20%EC%A0%95%EB%A6%AC/modifying_ex6.png)



## 3. remove 함수

remove함수의 정의는 다음과 같다.

```c++
template <class ForwardIterator, class T>
  ForwardIterator remove (ForwardIterator first, ForwardIterator last, const T& val)
{
  ForwardIterator result = first;
  while (first!=last) {
    if (!(*first == val)) {
      *result = move(*first);
      ++result;
    }
    ++first;
  }
  return result;
}
```



### remove 함수 소스코드 예시

```c++
#include <iostream>     // std::cout
#include <algorithm>    // std::remove
using namespace std;

bool IsOdd(int i) { return ((i % 2) == 1); }

int main() {
	int myints[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };      // 10 20 30 30 20 10 10 20

	// bounds of range:
	int* pbegin = myints;                          // ^
	int* pend = myints + sizeof(myints) / sizeof(int); // ^                       ^

	pend = remove_if(pbegin, pend, IsOdd);   // 2 4 6 8 ? ? ? ? ?
	for (int* p = pbegin; p != pend; ++p)
		cout << ' ' << *p;
	cout << '\n';

	pend = remove(pbegin, pend, 8);         // 2 4 6 ?
	for (int* p = pbegin; p != pend; ++p)
		cout << ' ' << *p;
	cout << '\n';

	return 0;
}
```



### remove 함수 소스코드 예시 실행결과

![실행 결과](https://github.com/Kyun2da/Algorithm/blob/master/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%20%EA%B0%9C%EB%85%90%20%EC%A0%95%EB%A6%AC/modifying_ex7.png)



## 4. transform 함수

transform 함수의 정의는 다음과 같다.

```c++
template <class InputIterator, class OutputIterator, class UnaryOperator>
  OutputIterator transform (InputIterator first1, InputIterator last1,
                            OutputIterator result, UnaryOperator op)
{
  while (first1 != last1) {
    *result = op(*first1);  // or: *result=binary_op(*first1,*first2++);
    ++result; ++first1;
  }
  return result;
}
```



### transform 함수 소스코드 예시

```c++
#include <iostream>
#include <cctype> // toupper, tolower
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main()
{

	string a = "abcABC.,!";
	string b = "";

	int len = a.size();

	b.resize(len);


	std::transform(a.begin(), a.end(), b.begin(), ::toupper);
	cout << b << endl;


	std::transform(a.begin(), a.end(), b.begin(), ::tolower);
	cout << b << endl;

	return 0;
}
```



### transform 함수 소스코드 예시 실행결과

![실행 결과](https://github.com/Kyun2da/Algorithm/blob/master/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%20%EA%B0%9C%EB%85%90%20%EC%A0%95%EB%A6%AC/modifying_ex8.png)  

