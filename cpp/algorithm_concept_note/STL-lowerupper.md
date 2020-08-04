# lower_bound 와 upper_bound

### lower_bound란?

- 이진탐색 기반의 탐색 방법으로써 이 방법 또한 리스트가 정렬되어 있어야만 한다.
- lower_bound는 찾으려하는 key값이 없으면 key값보다 큰 가장 작은 정수  값을 찾는다.
- 같은 원소가 여러개 있어도 상관 없기 때문에 항상 유일한 해를 구할 수 있다.
- 구간이 [start, end]인 배열이 있을 때, 중간위치의  index를 mid라고 하면, arr[mid-1] < key 이면서 arr[mid] >= key 인 최소의 m값을 찾으면 된다.

### lower_bound 구현과 사용법

- 직접 구현

  ```c++
  #include <iostream>
  using namespace std;
  
  int mylower_bound(int *arr, int n, int key){
      int start = 0;
      int end = n;
      int mid = n;
      
      while(end-start >0){
          mid = (start+end)/2;
          
          if(arr[mid] < key)
              start = mid +1;
          else
              end = mid;
      }
      
      return end+1;
  }
  
  int main(){
      int arr[10] = {1,2,4,5,6,6,7,7,7,9};
      
      cout << "lower_bound(6) : " << mylower_bound(arr,10,6) << endl;
      cout << "lower_bound(7) : " << mylower_bound(arr,10,7) << endl;
      cout << "lower_bound(8) : " << mylower_bound(arr,10,8) << endl;
      cout << "lower_bound(9) : " << mylower_bound(arr,10,9) << endl;
      reuturn 0;
  }
  ```

- STL 사용

  ```c++
  #include <iostream>
  #include <algorithm>
  
  using namespace std;
  
  int main()
  {
  	int arr[10] = { 1,2,4,5,6,6,7,7,7,9 };
  	
  	cout << "lower_bound(6) : " << lower_bound(arr, arr+10, 6) - arr + 1 << endl;
  	cout << "lower_bound(7) : " << lower_bound(arr, arr + 10, 7) - arr + 1 << endl;
  	cout << "lower_bound(8) : " << lower_bound(arr, arr + 10, 8) - arr + 1 << endl;
  	cout << "lower_bound(9) : " << lower_bound(arr, arr + 10, 9) - arr + 1 << endl;
  	return 0;
  }
  ```

  ### 결과

  두예시 둘다 5, 7, 10 , 10 을 출력하게 된다.



### upper_bound란?

- 이진탐색 기반의 탐색 방법으로써 이 방법 또한 리스트가 정렬되어 있어야만 한다.
- upper_bound는 찾으려하는 key값을 초과하는 가장 첫 번째 원소의 위치를 구하는 것이다.
- 같은 원소가 여러개 있어도 상관 없기 때문에 항상 유일한 해를 구할 수 있다.
- 구간이 [start, end]인 배열이 있을 때, 중간위치의  index를 mid라고 하면, arr[mid-1] <= key 이면서 arr[mid] > key 인 최소의 m값을 찾으면 된다.

### upper_bound 구현과 사용법

- 직접 구현

  ```c++
  #include <iostream>
  using namespace std;
  
  int myupper_bound(int *arr, int n, int key){
      int start = 0;
      int end = n;
      int mid;
      
      while(end-start >0){
          mid = (start+end)/2;
          
          if(arr[mid] <= key)
              start = mid +1;
          else
              end = mid;
      }
      
      return end+1;
  }
  
  int main(){
      int arr[10] = {1,2,4,5,6,6,7,7,7,9};
      
      cout << "upper_bound(6) : " << myupper_bound(arr,10,6) << endl;
      cout << "upper_bound(7) : " << myupper_bound(arr,10,7) << endl;
      cout << "upper_bound(8) : " << myupper_bound(arr,10,8) << endl;
      cout << "upper_bound(9) : " << myupper_bound(arr,10,9) << endl;
      reuturn 0;
  }
  ```

- STL 사용

  ```c++
  #include <iostream>
  #include <algorithm>
  
  using namespace std;
  
  int main()
  {
  	int arr[10] = { 1,2,4,5,6,6,7,7,7,9 };
  	
  	cout << "upper_bound(6) : " << upper_bound(arr, arr+10, 6) - arr + 1 << endl;
  	cout << "upper_bound(7) : " << upper_bound(arr, arr + 10, 7) - arr + 1 << endl;
  	cout << "upper_bound(8) : " << upper_bound(arr, arr + 10, 8) - arr + 1 << endl;
  	cout << "upper_bound(9) : " << upper_bound(arr, arr + 10, 9) - arr + 1 << endl;
  	return 0;
  }
  ```

  ### 결과

  두예시 둘다 7, 10, 10, 11  을 출력하게 된다.



### 마치며

여기서 알 수 있는 사실은 upper_bound - lower_bound 는 해당 원소의 갯수임을 알 수 있다.