'''
각 사람까지의 거리의 합이 최소
방법1. 각 위치에서의 거리합 계산하여 최솟값에 해당되는 마을의 위치 반환
방법2. 누적 사람 수가 총 인구 수의 절반을 넘어설 때 해당 마을의 위치에 우체국 설치
'''

import sys
input = sys.stdin.readline

list = []; peo = 0   # peo: 총 인구 수
people = 0           # people: 누적 인구 수
n = int(input())

for _ in range(n):
    x, a = map(int, input().split())
    list.append([x, a])
    peo += a
list = sorted(list, key = lambda x:x[0])

if peo % 2 != 0: peo = peo//2 + 1 
else: peo //= 2

for x, a in list:
    people += a

    if people >= peo: 
        print(x)
        break