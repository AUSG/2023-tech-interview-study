'''
case1. 벌-벌집-벌: 벌은 양 맨끝, 벌집은 꿀양이 가장 많은 곳에 위치
    - 이 케이스값을 max로 설정 후 비교
case2. 벌-벌-벌집 / 벌집-벌-벌
    - 한 마리는 가장 끝, 벌집은 그 반대편 끝에 위치
    - 다른 벌의 위치값(-) 나머지 값(+)
testcase.
7
9 9 4 1 4 9 9
-           -

'''

import sys
input = sys.stdin.readline

N = int(input())
loc = list(map(int, input().split()))
honey = 0; maxhoney = 0

# 벌-벌집-벌
maxhoney = sum(loc[1:-1]) + max(loc[1:-1])

# 벌-벌-벌집
for _ in range(1, N-1):
    honey = sum(loc[1:]) - loc[_] + sum(loc[_+1:])
    maxhoney = max(honey, maxhoney)

# 벌집-벌-벌
nloc = list(reversed(loc))
for _ in range(1, N-1):
    honey = sum(nloc[1:]) - nloc[_] + sum(nloc[_+1:])
    maxhoney = max(honey, maxhoney)

print(maxhoney)
