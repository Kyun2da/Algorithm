# 거품정렬(Bubble Sort)

### 개념

- 거품 정렬(Bubble sort)은 두 인접한 원소를 검사하여 정렬하는 가장 간단한 정렬 방법이다.

- 코드가 느리지만 코드가 단순하기 때문에 자주 사용되며, 원소의 이동이 거품이 수면으로 올라오는 듯한 모습을 보이기 때문에 지어진 이름이다.

![거품정렬 예](https://upload.wikimedia.org/wikipedia/commons/3/37/Bubble_sort_animation.gif)

- 거품정렬을 춤으로 구현해 놓은 동영상이다.


[![거품정렬을 춤으로 구현한 것](http://img.youtube.com/vi/lyZQPjUT5B4/0.jpg)](https://youtu.be/lyZQPjUT5B4?t=0s) 


### 시간복잡도

$$
O(n^2)
$$



### 정렬 과정

오름차순 정렬을 예로 들어보자

5 1 2 4 3 가 있다면 처음에는 5와 1을 비교한다. 5가 1보다 크므로 1과 5를 교환한다. 1 5 2 4 3

->그 후에 5 와 2를 비교한다 1 2 5 4 3 -> 5와 4를 비교한다 -> 1 2 4 5 3 -> 5 와 3을 비교한다

-> 1 2 4 3 5 이제 2부터 다시 정렬을 시작한다 -> 1 2 4 3 5 -> 1 2 3 4 5 

이런식으로 이중 for문을 돌며 정렬을 수행한다. 

### 소스코드

```c
void Bubble_Sort(int a[], int len) //ex. 54321 을 12345로 오름차순정렬 , 맨 뒤부터 큰수대로 정렬된다
{
	for (int i = len - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
```

[총 소스코드 예시](https://github.com/Kyun2da/BackJoonAlgorithm/blob/master/%EB%B0%B1%EC%A4%80%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/%EB%B2%84%EB%B8%94%20%EC%A0%95%EB%A0%AC/%EB%B2%84%EB%B8%94%20%EC%A0%95%EB%A0%AC/%EC%86%8C%EC%8A%A4.cpp)

### Reference

[거품정렬-위키백과]([https://ko.wikipedia.org/wiki/%EA%B1%B0%ED%92%88_%EC%A0%95%EB%A0%AC](https://ko.wikipedia.org/wiki/거품_정렬))

[거품정렬-블로그](https://bowbowbow.tistory.com/10)

