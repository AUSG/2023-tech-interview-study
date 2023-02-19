# 그래프 순회

> _그래프의 각 정점을 방문하는 과정; DFS와 BFS의 2가지 알고리즘 존재_

- 정점(v; vertex)과 간선(e; edge)의 집합

**그래프 표현 방법의 두 가지**

- 인접 행렬 (Adjacency Matrix)
  - key: 출발 노드, value: 도착 노드
- 인접 리스트 (Adjacency List)
  - 정점 개수만큼 인접 리스트 생성
<br>      


## DFS (_Depth-First Search, 깊이 우선 탐색)_

> _특정 경로로 탐색하며 최대한 깊숙이 들어가 노드를 방문한 후, 다른 경로를 탐색하는 알고리즘_

- 주로 스택이나 재귀로 구현
- 백트래킹을 통해 뛰어난 구현을 보임
- 데이터 개수가 N인 경우, 시간복잡도는 O(N)
- BFS보다 검색 속도는 느리지만, 더 간단하고 널리 쓰임
<br>      


**⍢ 스택으로 구현한 DFS**

① 탐색 시작 노드를 스택에 삽입 후 방문 처리

② 스택의 최상단 노드에 방문하지 않은 인접 노드가 존재할 시, 그 노드를 스택에 넣고 방문 처리

- 방문하지 않은 인접 노드가 없을 시, 스택에서 최상단 노드를 꺼냄

③ ②번의 과정 반복

```python
def iterative_dfs(start_v):
    discovered = []
	stack = [start_v]
	while stack:
		v = stack.pop()
		if v not discovered:
			discovered.append(v)
			for w in graph[v]:
				stack.append(w)
		return discovered
```

<br>      

**⍢ 재귀 구조로 구현한 DFS**

```python
def recursive_dfs(v, discovered=[]):
	discovered.append(v)    # discovered: 방문 정점
	for w in graph[v]:      # 현재 노드와 연결된 노드를 재귀적으로 방문
		if w not in discovered:
			discovered = recursive_dfs(w, discovered)
	return discovered
```
<br>      


### 백트래킹

> _해결책에 대한 후보를 구축해 나아가다 가능성이 없다고 판단되는 즉시 후보를 포기(Backtrack)하고 정답을 찾아가는 범용적인 알고리즘_

- 제약 충족 문제(CSP; Constraint Satisfaction Problem)에 특히 유용
  - CSP: 수많은 제약조건을 충족하는 상태를 찾아내는 문제
- 주로 재귀로 구현
<br>      



## BFS _(Breadth-First Search, 너비 우선 탐색)_

> _가까운 노드부터 탐색하는 알고리즘_

- 주로 큐로 구현
  - collections 모듈의 deque 자료구조를 활용
- 그래프의 최단 경로를 찾는 다익스트라 알고리즘에 유용하게 활용
- 데이터 개수가 N인 경우, 시간복잡도는 O(N)
  - 실제 수행 시간은 DFS보다 좋음
- BFS는 재귀적으로 동작하지 않는다.
<br>      


**⍢ 큐를 이용한 BFS**

① 탐색 시작 노드를 큐에 삽입하고 방문 처리

② 큐에서 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은 노드를 모두 큐에 삽입하고 방문 처리

③ ②번의 과정 반복

```python
def iterative_bfs(start_v):
	discovered = [start_v]
	queue = [start_v]
	while queue:
		v = queue.pop(0)
		for w in graph[v]:
			if w not in discovered:
				discovered.append(w)
				queue.append(w)
	return discovered
```

---

🥕 Reference

- 파이썬 알고리즘 인터뷰
- 이것이 코딩 테스트다 with 파이썬
