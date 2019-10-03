# 삽입정렬(insertion sort)

### 개념

삽입정렬은 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여, 자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘이다.

배열이 길어질수록 효율이 떨어지지만, 구현이 간단하다는 장점이 있다.

![삽입정렬 예시](https://upload.wikimedia.org/wikipedia/commons/2/25/Insertion_sort_animation.gif)



### 시간복잡도

![](https://camo.githubusercontent.com/11f1c7cef45063b67debbddc2d223af1b113883d/68747470733a2f2f6c617465782e636f6465636f67732e636f6d2f6769662e6c617465783f4f286e5e3229)

### 정렬 원리

- 해당 원소(빨간색 원소)를 어느자리(회색자리+빨간색자리중에서)에 삽입할 것이느냐의 문제

![삽입 정렬 예시](https://upload.wikimedia.org/wikipedia/commons/e/ea/Insertion_sort_001.PNG)

### 소스코드

```c
void Insertion_Sort(int arr[], int len)
{
	int i, j, remember;
	for (i = 1; i < len; i++)
	{
		remember = arr[i]; //삽입될 숫자를 기억해 놓는다.

		//remember보다 arr[j]값이 크면 arr[j]를 arr[j+1]로 이동
		for (j = i - 1; j >= 0 && arr[j] > remember; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = remember;
	}
}
```

[총 소스코드 예시]([https://github.com/Kyun2da/BackJoonAlgorithm/blob/master/백준알고리즘/삽입%20정렬/삽입%20정렬/소스.cpp](https://github.com/Kyun2da/BackJoonAlgorithm/blob/master/%EB%B0%B1%EC%A4%80%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/%EC%82%BD%EC%9E%85%20%EC%A0%95%EB%A0%AC/%EC%82%BD%EC%9E%85%20%EC%A0%95%EB%A0%AC/%EC%86%8C%EC%8A%A4.cpp)

### Reference

[삽입정렬(나무위키)]([https://ko.wikipedia.org/wiki/%EC%82%BD%EC%9E%85_%EC%A0%95%EB%A0%AC](https://ko.wikipedia.org/wiki/삽입_정렬))

### Bonus

- 삽입정렬을 춤으로 구현한 동영상

[![Video Label](http://img.youtube.com/vi/ROalU379l3U/0.jpg)](https://youtu.be/ROalU379l3U?t=0s)
