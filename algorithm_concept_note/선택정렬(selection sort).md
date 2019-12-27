# 선택정렬(selection sort)

### 개념

- 선택정렬은 제자리 정렬의 알고리즘 중 하나로,  다음과 같은 순서로 이루어진다

  1.  주어진 리스트 중에 최소값을 찾는다

  2.  그 값을 맨 앞에 위치한 값과 교체한다.

  3.  맨 처음 위치를 뺀 나머지 리스트를 같은 방법으로 교체한다
  
- 선택정렬은 알고리즘이 단순하여 구현하기 쉽다는 장점이 있지만 효율이 좋지는 않다.
  

![선택 정렬](https://upload.wikimedia.org/wikipedia/commons/b/b0/Selection_sort_animation.gif)

### 정렬 과정

- 해당 인덱스(노란색)에 들어갈 원소(빨간색) 순환하며 찾는다.
- 노란색-해당인덱스, 빨간색-순환하며 찾은 최소값, 파란색-순환과정

![정렬 이미지](https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif)

###   소스코드

```c++
void Selection_Sort(int arr[], int len)
{
	int i, j, indexMin, temp;
	
	for (i = 0; i < len - 1; i++)
	{
		indexMin = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[indexMin])
			{
				indexMin = j;
			}
		}
		temp = arr[indexMin];
		arr[indexMin] = arr[i];
		arr[i] = temp;
	}
}
```

[총 소스코드](https://github.com/Kyun2da/BackJoonAlgorithm/blob/master/%EB%B0%B1%EC%A4%80%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/%EC%84%A0%ED%83%9D%20%EC%A0%95%EB%A0%AC/%EC%84%A0%ED%83%9D%20%EC%A0%95%EB%A0%AC/%EC%86%8C%EC%8A%A4.cpp)

### Reference

[나무위키](https://ko.wikipedia.org/wiki/선택_정렬)

### Bonus

[![Video Label](http://img.youtube.com/vi/Ns4TPTC8whw/0.jpg)](https://youtu.be/Ns4TPTC8whw?t=0s)

