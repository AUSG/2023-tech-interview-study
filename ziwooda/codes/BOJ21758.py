'''
case1. 벌-벌집-벌: 벌은 양 맨끝, 벌집은 꿀양이 가장 많은 곳에 위치
    - 이 케이스값을 max로 설정 후 비교
case2. 벌-벌-벌집 / 벌집-벌-벌
    - 한 마리는 가장 끝, 벌집은 그 반대편 끝에 위치
    - 다른 벌의 위치값(-) 나머지 값(+) ; 이 방법은 N이 커질 때 Runtime Error 발생
    - 나머지 값을 더하는 대신 벌 위치를 옮겨가면서 전체 꿀양에서 위치값(-)
'''

import sys
input = sys.stdin.readline

N = int(input())
loc = list(map(int, input().split()))
honey = 0; maxhoney = 0
total = sum(loc[:])

# 벌-벌집-벌
maxhoney = sum(loc[1:-1]) + max(loc[1:-1])

# 벌-벌-벌집
bee1 = sum(loc[1:]); bee2 = loc[0]
for _ in range(1, N-1):
    bee2 += loc[_]
    honey = bee1 - loc[_] + total - bee2
    maxhoney = max(honey, maxhoney)

# 벌집-벌-벌
nloc = list(reversed(loc))
bee1 = sum(nloc[1:]); bee2 = nloc[0]
for _ in range(1, N-1):
    bee2 += nloc[_]
    honey = bee1 - nloc[_] + total - bee2
    maxhoney = max(honey, maxhoney)

print(maxhoney)
