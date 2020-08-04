# STL Library - string

string 함수는 c언어의 문자열헤더 string.h의 진화형으로 볼 수 있다.

문자열을 사용할 때 사용하면 편리한 함수들이 모여있다

### string 선언 방법

```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;
	string str2;
	string str3;

	cin >> str1;  //공백을 집어넣을 수없음
	getchar();
	getline(cin, str2); //엔터를 입력할때까지 문자열을 입력받음
	getline(cin, str3, 'a'); // a 문자 앞까지만 입력받음
	cout << str1;
	cout << "str은 : " <<str1 << endl;
	cout << "str2는 : " << str2 <<endl;
	cout << "str3은 : " << str3 << endl;
    
    return 0;
}
```



## string 함수

지금부터 string 함수와 그에따른 예제들을 보여주도록 하겠다

* 문자열이 같은지 비교할 떄 ==을 써서 비교한다.

  ```c++
  string name1 = "appaa";
  string name2 = "appbb";	cout << "두개의 문자열이 같나요? "<<(str1 == str2) << endl; //같으면 1을 반환하고 다르면 0을 반환한다
  ```

  

* 문자열 사전순서 비교  >과 <를 써서 비교한다

  ```
  cout << "str1이 더 사전순으로 뒤에있나요?(str1이 더큰가요?)  : " << (str1 > str2) << endl;
  cout << "str2가 더 사전순으로 뒤에있나요?(str2가 더큰가요?)  : " << (str1 < str2) << endl;
  ```

  

* **compare함수**로 문자열 비교 하기

  ```c++
  int result;
  string name1 = "appaa";
  string name2 = "appbb";
  
  result = name1.compare(name2); // 문자열이 같으면 0을, 매개 객체보다 앞순이면 -1을, 매개 객체보다 뒷순이면 1을 반환함
  
  if (result == 0)
  	cout << "두 문자열은 같음" << endl;
  
  else if (result < 0)
  	cout << "name1이 앞에옴" << endl;
  
  else if (result > 0)
  	cout << "name2이 앞에옴" << endl;
  
  cout << result << endl;
  ```

  

* **length, size, capacity 함수**를 사용하여 길이를 비교한다

  ```c++
  string str = "012345";
  
  cout << str.length() << endl;    // 6 문자열길이 반환
  cout << str.size() << endl;      // 6 문자열길이 반환(length, size는 동작결과가 동일함)
  cout << str.capacity() << endl;  // 22 이 객체가 사용중인 메모리 크기(가변)
  ```

  

* append함수 또는 += 사용해서 문자열 뒤에 문자열 잇기

  ```c++
  string str = "aaa";
  
  str.append("bbb");
  cout << str << endl;   // "aaabbb"
  
  str += "ccc";
  cout << str << endl;   // "aaabbbccc"
  ```

  

* **insert함수** 사용해서 주어진 위치에 문자열 삽입

  ```c++
  string str = "012345";
  
  str.insert(2, "bbb"); // index가 2인 위치에 있는 문자 앞에 삽입함.
  cout << str << endl; // "01bbb2345"
  ```

  

* **replace 함수** 사용해서 주어진위치의 글자수를 해당문자열로 교체

  ```c++
  string str = "012345";
  
  str.replace(2, 3, "bbb"); // index가 2인 위치에 있는 문자부터 ~ 3개의 문자를 "bbb"로 대체함
  cout << str << endl;    // "01bbb5"
  
  //erase함수 사용해서 주어진 위치의 글자수를 삭제
  string str = "012345";
  
  str.erase(1, 4);       // index 1 ~ 4 인 부분을 부분적으로 지움
  
  cout << str << endl;   // "05"
  ```

  

* **clear함수** 사용에서 문자열 전체 삭제

  ```c++
  string str = "012345";
  
  str.clear();           // 저장되어 있는 문자열을 모두 지움
  
  cout << str << endl;   
  ```

  

* **substr함수** 사용해서 문자열의 일부분을 받아옴

  ```c++
  string str = "012345";
  
  cout << str.substr(2) << endl;    // "2345"  index 2의 위치부터 ~ 끝까지의 문자를 반환함
  cout << str.substr(2, 3) << endl;  // "234"   index 2의 위치부터 3개의 문자를 반환함
  ```

  

* **find 함수** 사용해서 해당 문자열이 존재하는지 판단

  ```c++
  string str = "kkk abc aaa";
  int result;
  
  result = str.find("f");
  cout << result << endl;  // -1 : "f" 가 존재하지 않으므로.
  
  result = str.find("aac");
  cout << result << endl;  // -1 : "aac" 가 존재하지 않으므로.
  
  result = str.find("aaa");
  cout << result << endl;  //  8 : "aaa" 가 시작되는 인덱스가 8이므로.
  
  result = str.find("kkk", 4);
  cout << result << endl;  //  -1 : 인덱스 4의 위치부터 "kkk" 를 찾는데 존재하지 않으므로.
  ```

  

* **[] 또는 at함수** 사용해서 문자한개를 반환

  ```c++
  string str = "012345";
  char c;
  
  c = str[1];
  cout << c << endl;
  
  c = str.at(1); // 위와 동일한 표현
  cout << c << endl;
  ```

  


* **stoi또는 to_string함수**를 통해 문자열을 숫자로 변환하거나 숫자를 문자열로 변환시켜줌

  ```c++
  // string의 문자열 전체를 숫자로 변환하는 경우
  string str = "2000";
  int a = stoi(str);
  
  // string의 문자 한개를 숫자로 변환하는 경우
  string str = "2000";
  string temp;
  temp = str[0];         // index를 포함한 값인 경우 여기처럼 선언과 할당을 분리시켜줘야 한다.
  int b = stoi(temp);
  
  int a = 12;
  string str;
  str = to_string(a);
  ```

  

*  **toupper 이나 tolower** 을 사용해서 문자를 변환

  ```c++
  string str = "abcde";
  str[2] = toupper(str[2]);
  cout << str;               // "abCde"
  
  string str = "abcde";
  str[2] = tolower(str[2]);
  cout << str;               // "ABcDE"
  ```

  

* **isdigit함수**를 사용해서 해당 문자가 숫자인지 알려줌

  ```C++
  string str = "1ABCDE";
  
  cout << isdigit(str[0]) << endl; // 1(true)
  cout << isdigit(str[2]) << endl; // 0(false)
  ```

  

* **isalpha함수**를 사용해서 해당문자가 알파벳인지 알려줌

  ```c++
  string str = "1ABCDE";
  
  cout << isalpha(str[0]) << endl; // 0(false)
  cout << isalpha(str[2]) << endl; // 1(true)
  ```

  

* **empty함수**를 사용해서 문자열이 비어있는지 알려줌

  ```c++
  string str1 = "";
  cout << str1.empty() << endl; // 1(true)
  
  string str2 = "abcde";
  cout << str2.empty() << endl; // 0(false)
  ```

  

* **swap함수**를 사용해서 문자열을 서로 교환함

  ```c++
  string str1 = "aaa";
  string str2 = "ccc";
  
  str1.swap(str2);
  
  cout << str1 << endl; // "ccc"
  cout << str2 << endl; // "aaa"
  ```

  

* **pop_back() 또는 push_back()함수**를 사용해서 맨뒤의 문자를 pop하거나 push함

  ```c++
  string str = "abc";
  
  str.pop_back();
  cout << str << endl; // "ab"
  
  str.push_back('c');
  cout << str << endl; // "abc"
  ```

  

* **front나 back 함수**를 사용해서 맨앞이나 맨뒤의 문자를 반환함

  ```c++
  string str = "abc";
  
  cout << str.front() << endl; // "a"
  cout << str.back() << endl;  // "c"
  ```

  
