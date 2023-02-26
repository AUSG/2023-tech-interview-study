# Binary Search

## 순차 탐색 (Sequential Search)

> _리스트 안의 특정 데이터를 찾기 위해 앞에서부터 하나씩 차례대로 확인하는 방법_

- 데이터 개수가 N이면 시간복잡도는 O(N)
- count() 메소드 사용 시에도 순차 탐색 기법이 수행

```python
# 순차 탐색 함수
def sequential_search(n, target, array):
	for i in range(n):
		if array[i] == target:
			return i+1

input_data = input().split()    # 생성할 원소 개수와 문자열 입력
n = int(input_data[0])  # 원소 개수
target = input_data[1]  # 찾으려는 문자열

array = input().split()   # n개만큼 문자열 입력

print(sequential_search(n, target, array))
```

---

## 이진 탐색 (Binary Search)

> _정렬되어 있는 데이터에서 타겟을 찾는 검색 알고리즘으로, 중간 위치의 데이터부터 반복적으로 비교_

- 데이터 개수가 N이면 시간복잡도는 O(logN)
- 탐색 범위의 **시작점**, **끝점**, **중간점**의 3개 변수를 사용

**⍢ 재귀 함수로 구현한 이진 탐색**

```python
def binary_search(array, target, start, end):
	if start > end:
		return None
	mid = (start+end) // 2

	if array[mid] == target:    # target이 mid 위치에 있는 경우
		 return mid
	elif array[mid] > target:   # target이 mid 위치의 데이터보다 작은 경우 왼쪽으로 포인터 이동
		return binary_search(array, target, start, mid-1)
	elif array[mid] < target:   # target이 mid 위치의 데이터보다 큰 경우 오른쪽으로 포인터 이동
		return binary_search(array, target, mid+1, end)
```

**⍢ 반복문으로 구현한 이진 탐색**

```python
def binary_search(array, target, start, end):
	while start <= end:
		mid = (start+end) // 2

		if array[mid] == target:
			return mid
		elif array[mid] > target:
			end = mid - 1
		else:
			start = mid + 1
	return None
```

⍥ **시간복잡도 정리**

| 순차탐색 | O(N)    |
| -------- | ------- |
| 이진탐색 | O(logN) |

---

**🥕 Reference**

- 파이썬 알고리즘 인터뷰
- 이것이 코딩 테스트다 with 파이썬
