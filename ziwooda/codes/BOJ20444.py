'''
N = row+col
pieces = (row+1)*(col+1)
ex. n=7; (1, 6), (2, 5), (3, 4) -> 14, 18, 20
⇒ row값이 커질수록 pieces값도 커지는 것을 활용하여 중간지점부터 비교
'''

import sys
input = sys.stdin.readline

N, k = map(int, input().split())
left = 0; right = N//2

def cutPieces(left, right):
    while left <= right:
        row = (left+right) // 2

        piece = (row + 1) * (N - row + 1)
        if piece < k:
            return cutPieces(row+1, right)
        elif piece > k:
            return cutPieces(left, row-1)
        else:
            return 'YES'
    return 'NO'

print(cutPieces(left, right))