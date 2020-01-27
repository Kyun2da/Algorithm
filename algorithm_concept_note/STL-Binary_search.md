# 이진탐색(Binary Search)

### 이진탐색이란?

- 이진 탐색은 오름차순으로 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘이다.

- 정렬된 리스트에서만 사용할 수 있다는 단점이있다.
- 선형탐색 보다 훨씬 빠르다

- 시간 복잡도는 logn이다 밑은 2

### 

### 이진탐색 구현(방법 3가지)

- 직접구현 (반복문을 이용한 이진 탐색)

  ```c++
  bool BinarySearch(int *arr, int len, int key)
  {
  	int start = 0;
  	int end = len -1;
  	int mid;
  	
  	while(end - start >= 0){
  		mid = (start + end) / 2;
  		
  		if(arr[mid] == key)
  			return true;
  		
  		else if(arr[mid] >key)
  			end = mid - 1;
  		else
  			start = mid + 1;
  	}
  	return false;
  }
  ```

  

- 직접구현 (재귀를 이용한 이진 탐색)

  ```c++
  bool BinarySearch(int *arr, int start, int end, int key){
      if(start > end)
          return false;
      
      int mid = (start + end) / 2;
      if(arr[mid] == key)
          return true;
      else if(arr[mid] > key)
          return BinarySearch(arr, start, mid-1, key);
      else
          return BinarySearch(arr, mid+1, end, key);
  }
  ```

  

- STL 이용 ( algorithm 헤더 안에 있는 것 이용)

  ```c++
  #include <iostream>
  #include <algorithm>
  using namespace std;
  
  int main(){
      int n =100;
      int arr[n];
      
      for(int i=0; i<n; i++)
          arr[i] = i;
      
      cout << "exist : " << binary_search(arr, arr+n, 70) << endl;
      
      return 0;
  }
  ```

  

